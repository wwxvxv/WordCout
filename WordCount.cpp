#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  

	int is_delimiter(char c) {  

	    // �ո񣬶��ţ�ˮƽ�Ʊ�������з����Ƿָ���  

	    return c == ' ' || c == ',' || c == '\t' || c == '\n';  

	}  

	  

	int main(int argc, char *argv[]) {  

	    if (argc != 3) {  

	        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  

	        return 1;  

	    }  

	  

	    char *mode = argv[1];  

	    char *filename = argv[2];  

	  

	    FILE *file = fopen(filename, "r");  

	    if (!file) {  

	        perror("Error opening file");  

	        return 1;  

	    }  

	  

	    int char_count = 0;  

	    int word_count = 0;  

	    int in_word = 0; // ����Ƿ����ڴ���һ������  

	  

	    char ch;  

	    while ((ch = fgetc(file)) != EOF) {  

	        char_count++; // ��ȡ���ַ����ַ�����1  

	  

	        if (is_delimiter(ch)) {  

	            if (in_word) {  

	                word_count++; // ���ʽ�������������1  

	                in_word = 0;  

	            }  

	        } else {  

	            if (!in_word) {  

	                in_word = 1; // ���ʿ�ʼ  

	            }  

	        }  

	    }  

	  

	    // ������һ���ַ����Ƿָ���������Ӧ�ñ���Ϊ���ʵ�һ����  

	    if (in_word) {  

	        word_count++;  

	    }  

	  

	    fclose(file);  

	  

	    if (strcmp(mode, "-c") == 0) {  

	        printf("�ַ�����%d\n", char_count);  

	    } else if (strcmp(mode, "-w") == 0) {  

	        printf("��������%d\n", word_count);  

	    } else {  

	        fprintf(stderr, "Invalid mode: %s\n", mode);  

	        return 1;  

	    }  

	  

	    return 0;  

	}
