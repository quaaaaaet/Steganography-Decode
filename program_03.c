#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	printf("-------------------------------\n������ �޼����� �ѹ� �о��!!!\n-------------------------------\n\n");
	FILE* fo = fopen("output.bmp", "rb");

	if (fo == NULL) {
		printf("File open failed\n");
		return 1;

	}

	//���� ������
	fgetc(fo);
	fgetc(fo);

	int FILESIZE = 0;
	fread(&FILESIZE, sizeof(int), 1, fo);
	
	//5-9 BYTE �н�
	fgetc(fo); fgetc(fo); fgetc(fo); fgetc(fo);

	//�ȼ���ŸƮ���� �б�
	int PIXELSTART = 0;
	fread(&PIXELSTART, sizeof(int), 1, fo);
	
	rewind(fo);

	char c;
	//�ȼ����������� ��ŵ
	for (int i = 0; i < PIXELSTART; i++) {
		c = fgetc(fo);
	}

	unsigned char m; //�׳� char������ ���,�����ؼ� 127�ۿ� ���Ұ� => unsignedó��
	unsigned char s;


	for (int a = PIXELSTART; a < FILESIZE; a += 4) { //�ȼ� ���������� ���� ũ����� 4byte�� ���µ�
		fgetc(fo);
		fgetc(fo);
		fgetc(fo);
		m = fgetc(fo);
		m = (int)(m);
		if (m != 255) { //�ȼ��� ������ ff, 255���� ä���� �����Ƿ� ff�� �ƴϸ�
			s = (char)(m); //�� ���ھ� �������� 
			printf("%c", s);
		}
		else {
			break;
		}
	}
	fclose(fo);
	return 0;
}