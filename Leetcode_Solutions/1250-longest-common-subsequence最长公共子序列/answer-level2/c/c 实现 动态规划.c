#include <stdlib.h>
#include <string.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
//int dp[1000][1000];
int longestCommonSubsequence(char * text1, char * text2)
{
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int i;
    int j;
    int len = MAX(len1, len2);
    
    int **dp = malloc(sizeof(int*)*len2);
    for (i = 0; i < len2; i++) {
        dp[i] = calloc(len1, sizeof(int));
    }
    if (len1 == 0 || len2 == 0) {
        return 0;
    }
    //memset_s(dp, sizeof(dp), 0, sizeof(dp));
   // memset(dp,  0, sizeof(dp));
    for (i = 0; i < len1; i++) {
        if (text1[i] == text2[0]) {
            for (j = i; j < len1; j++) {
                dp[0][j] = 1;
            }
            break;
        } else {
            dp[0][i] = 0;
        }
    }
    for (i = 0; i < len2; i++) {
        if (text1[0] == text2[i]) {
            for (j = i; j < len2; j++) {
                dp[j][0] = 1;
            }
            break;
        } else {
            dp[i][0] = 0;
        }
    }
    for (i = 1; i < len2; i++) {
        for (j = 1; j < len1; j++) {
            if (text2[i] == text1[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;                
            } else {
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len2-1][len1-1];
}