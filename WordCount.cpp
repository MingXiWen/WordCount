#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int countWo(char *path){
	FILE *fp;
	char buffer[5000],ch;
	int len=0,lastCh=1,count=0,i;
	if((fp=fopen(path,"r"))!=NULL){//打开文件成功开始读取 
		while(fgets(buffer,1000,fp)!=NULL){//从给定文件流读取至多 999个字符，并存储它们于 buffer数组 。若出现文件尾条件或找到换行符则读取停止
			len=strlen(buffer);
			for(i=0;i<len;i++){
				ch=buffer[i];
				if(ch==' '||ch==','){
					if(lastCh==0){//表明上一个为一个单词
					    count++;
					}
					lastCh=1;//标记此处为分隔符 
				}
					else if(ch!='\n'&&ch!='\r')
					    lastCh=0;
					
			}
				if(lastCh==0)//如果最后一个字符不是换行 
				   count++;
			lastCh=1;
		}
	} 
	else{
		printf("文件打开失败");
		exit(0);
	}
	fclose(fp);
	printf("单词数：%d\n",count);
	exit(0);
}
int countCh(char *path){
	FILE *fp;
	int count=0;
	char ch;
	fp=fopen(path,"r");
	if(fp!=NULL){
		while(!feof(fp)){
			ch=fgetc(fp);//读取来自给定输入流的下个字符。 
			count++;
		}
	}else{
		printf("文件打开失败");
		exit(0); 
	}
	fclose(fp);
	printf("字符数：%d\n",count-1);
	exit(0);
}
int main(int argc,char* argv[]){
	FILE *fp;
	printf("--------------\n-w 输出单词数目\n-c 输出字符数目\n--------------\n ");
	while(1){
		if((fp=fopen(argv[2],"r"))==NULL){
			printf("该文件不存在\n");
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
