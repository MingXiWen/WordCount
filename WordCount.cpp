#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int countWo(char *path){
	FILE *fp;
	char buffer[5000],ch;
	int len=0,lastCh=1,count=0,i;
	if((fp=fopen(path,"r"))!=NULL){//���ļ��ɹ���ʼ��ȡ 
		while(fgets(buffer,1000,fp)!=NULL){//�Ӹ����ļ�����ȡ���� 999���ַ������洢������ buffer���� ���������ļ�β�������ҵ����з����ȡֹͣ
			len=strlen(buffer);
			for(i=0;i<len;i++){
				ch=buffer[i];
				if(ch==' '||ch==','){
					if(lastCh==0){//������һ��Ϊһ������
					    count++;
					}
					lastCh=1;//��Ǵ˴�Ϊ�ָ��� 
				}
					else if(ch!='\n'&&ch!='\r')
					    lastCh=0;
					
			}
				if(lastCh==0)//������һ���ַ����ǻ��� 
				   count++;
			lastCh=1;
		}
	} 
	else{
		printf("�ļ���ʧ��");
		exit(0);
	}
	fclose(fp);
	printf("��������%d\n",count);
	exit(0);
}
int countCh(char *path){
	FILE *fp;
	int count=0;
	char ch;
	fp=fopen(path,"r");
	if(fp!=NULL){
		while(!feof(fp)){
			ch=fgetc(fp);//��ȡ���Ը������������¸��ַ��� 
			count++;
		}
	}else{
		printf("�ļ���ʧ��");
		exit(0); 
	}
	fclose(fp);
	printf("�ַ�����%d\n",count-1);
	exit(0);
}
int main(int argc,char* argv[]){
	FILE *fp;
	printf("--------------\n-w ���������Ŀ\n-c ����ַ���Ŀ\n--------------\n ");
	while(1){
		if((fp=fopen(argv[2],"r"))==NULL){
			printf("���ļ�������\n");
			exit(0);
		} 
		if(!strcmp(argv[1],"-w"))
		    countWo(argv[2]);
		if(!strcmp(argv[1],"-c"))
		    countCh(argv[2]);

		printf("\n-----\n");
	scanf("%s%s%s",&argv[0],&argv[1],&argv[2]);
		
	}
}
