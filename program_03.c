#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	printf("-------------------------------\n숨겨진 메세지를 한번 읽어보자!!!\n-------------------------------\n\n");
	FILE* fo = fopen("output.bmp", "rb");

	if (fo == NULL) {
		printf("File open failed\n");
		return 1;

	}

	//파일 사이즈
	fgetc(fo);
	fgetc(fo);

	int FILESIZE = 0;
	fread(&FILESIZE, sizeof(int), 1, fo);
	
	//5-9 BYTE 패스
	fgetc(fo); fgetc(fo); fgetc(fo); fgetc(fo);

	//픽셀스타트지점 읽기
	int PIXELSTART = 0;
	fread(&PIXELSTART, sizeof(int), 1, fo);
	
	rewind(fo);

	char c;
	//픽셀시작점까지 스킵
	for (int i = 0; i < PIXELSTART; i++) {
		c = fgetc(fo);
	}

	unsigned char m; //그냥 char선언은 양수,음수해서 127밖에 사용불가 => unsigned처리
	unsigned char s;


	for (int a = PIXELSTART; a < FILESIZE; a += 4) { //픽셀 시작점부터 파일 크기까지 4byte씩 도는데
		fgetc(fo);
		fgetc(fo);
		fgetc(fo);
		m = fgetc(fo);
		m = (int)(m);
		if (m != 255) { //픽셀의 투명도는 ff, 255으로 채워져 있으므로 ff가 아니면
			s = (char)(m); //한 문자씩 가져오기 
			printf("%c", s);
		}
		else {
			break;
		}
	}
	fclose(fo);
	return 0;
}