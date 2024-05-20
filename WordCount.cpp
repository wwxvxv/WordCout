#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  

	int is_delimiter(char c) {  

	    // 空格，逗号，水平制表符，换行符都是分隔符  

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

	    int in_word = 0; // 标记是否正在处理一个单词  

	  

	    char ch;  

	    while ((ch = fgetc(file)) != EOF) {  

	        char_count++; // 读取到字符，字符数加1  

	  

	        if (is_delimiter(ch)) {  

	            if (in_word) {  

	                word_count++; // 单词结束，单词数加1  

	                in_word = 0;  

	            }  

	        } else {  

	            if (!in_word) {  

	                in_word = 1; // 单词开始  

	            }  

	        }  

	    }  

	  

	    // 如果最后一个字符不是分隔符，则它应该被视为单词的一部分  

	    if (in_word) {  

	        word_count++;  

	    }  

	  

	    fclose(file);  

	  

	    if (strcmp(mode, "-c") == 0) {  

	        printf("字符数：%d\n", char_count);  

	    } else if (strcmp(mode, "-w") == 0) {  

	        printf("单词数：%d\n", word_count);  

	    } else {  

	        fprintf(stderr, "Invalid mode: %s\n", mode);  

	        return 1;  

	    }  

	  

	    return 0;  

	}
