#include <stdlib.h>
#include <stdio.h>

char **g_solves;
int g_solveCnt;
char *g_midstr = NULL;

char g_map[8][4] = {
        {'a','b','c','0'},
        {'d','e','f','0'},
        {'g','h','i','0'},        
        {'j','k','l','0'},
        {'m','n','o','0'},
        {'p','q','r','s'},
        {'t','u','v','0'},
        {'w','x','y','z'},
    };

/* 每个数字对应的字母个数 */
int charnum(char c)
{
    switch(c)
    {
        case '2':
            return 3;
        case '3':
            return 3;
        case '4':
            return 3;
        case '5':
            return 3;
        case '6':
            return 3;
        case '7':
            return 4;
        case '8':
            return 3;
        case '9':
            return 4;                    
    }
    
    return 0;        
}

/* 字母转换为数字 */
int maptoint(char c)
{
    switch(c)
    {
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;                    
    }
    
    return 0;        
}

char *rowunit;
int count = 0;

/* 将每一个解保存起来 */
void OutputOneResult(int n) {
            
    for (int i = 0; i < n; i++)
    {
        g_solves[count][i] = rowunit[i];        
    }
    
    count++;
        
    return;
}

/* 放置字符 */
void PlaceQueen(int n, int i, int index, char *digits)
{       
    int num = maptoint(digits[index]);
        
    rowunit[index] = g_map[num-2][i];    
           
    return;
}

/* 回溯法，通过函数封装，整理为经典的代码结构
    1、判断是否为解，是则输出解
    2、不是解，本层放置记录放置的字符，进入递归进入下一层
    3、本层解已经求完解，递归函数return，回溯到上一层，到下一个合适的位置摆放
    4、全部完成求解，输出 */
void BackTrack(int n, int index, char *digits)
{
    char currentchar ;
    
    if (index >= n) {
        OutputOneResult(n);
        return;
    }
    
    currentchar = digits[index];
    
    for (int i = 0; i < charnum(currentchar); i++) {
        PlaceQueen(n, i, index, digits);        
        BackTrack(n, index + 1, digits);
    }
    
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){    
    char *ptr = digits;
    int size;
    int num = 1;
    int levelmax = strlen(digits);
    
    if (levelmax == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    
    while(*ptr != '\0')
    {
        num = num*charnum(*ptr);
        ptr++;        
    }    
    
    rowunit = (char *)malloc(sizeof(char) * levelmax);
    
    g_solves = (char **)malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++)
    {
        g_solves[i] = (char *)malloc((levelmax+1)*sizeof(char));
        memset((char *)(g_solves[i]), 0, (levelmax+1)*sizeof(char));
    }
            
    BackTrack(levelmax, 0, digits);
                
    *returnSize = num;
    
    free(rowunit);
    
    count = 0;
        
    return g_solves;        
}