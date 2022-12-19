解法比较暴力，遍历两句话，通过一个全局数据记录不重复的单词，同步同步记录各单词出现的次数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM  " "
#define MAX_NUM 101

char* g_words[MAX_NUM];
int g_count[MAX_NUM];
int g_size;
char g_str1[201];
char g_str2[201];

void fillWords(char* str, const char* delim)
{
    char *tok;
    char *save = NULL;
    int i;

    tok = strtok_r(str, delim, &save);
    while (tok) {
        for (i = 0; i < g_size; i++) {
            if (strcmp(g_words[i], tok) == 0) {
                g_count[i]++;
                break;
            }
        }
        if (i == g_size) {
            g_words[g_size] = tok;
            g_size++;
            g_count[i]++;
        }

        tok = strtok_r(NULL, delim, &save);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** uncommonFromSentences(char * A, char * B, int* returnSize){
    int i, j;

    char **ans = (char **)malloc(MAX_NUM * sizeof(char*));
    memset(ans, 0, MAX_NUM * sizeof(char*));

    memset(g_count, 0, sizeof(g_count));
    memset(g_words, 0, sizeof(g_words));
    g_size = 0;
    *returnSize = 0;

    memset(g_str1, 0, sizeof(g_str1));
    strcpy(g_str1, A);

    memset(g_str2, 0, sizeof(g_str2));
    strcpy(g_str2, B);
    fillWords(g_str1, DELIM);
    fillWords(g_str2, DELIM);

    for (i = 0, j = 0; i < g_size; i++) {
        if (g_count[i] == 1) {
            ans[j] = g_words[i];
            *returnSize += 1;
            j++;
        }
    }

    return ans;
}

/*
int main()
{
    int size, i, j;
    char **p;

    char* cases[][2] = {
        "this apple is sweet", "this apple is sour",
        "apple apple", "app",
        "ngd wk cqjxlql vcmeek hz dv mprvef sl xf uwiyba as ijtse azppe h mprvef mlordok rguls psfoo llf psfoo mcfsng azmle zhii sl psfoo ebgb sfcyye sfcyye sypfxev atnp ngd fycx mprvef wk gnj obbobwq mcfsng", "sfcyye rguls as u st vcmeek td hjyfh as xf qjfwa yxf qjfwa a azppe azmle mlordok zhii uwiyba ngd ebgb j j rguls gnj mprvef wzrl atnp wzrl hjyfh ebgb obbobwq vfajd uwiyba llf sfcyye jur as ozif vfajd",
    };

  */                