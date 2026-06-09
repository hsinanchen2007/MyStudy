```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool checkValid(int len, char str[])
{
    char checkStr[len];
    int checkLen = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            checkStr[checkLen++] = '(';   
        } else {
            if (checkLen > 0 && checkStr[checkLen - 1] == '(') {
                checkLen--;
            } else {
                return false;
            }
        }
    }
    if (checkLen == 0) {
        return true;
    } 
    return false;
}
#define MAX_NUM 20
#define MAX_COUNT 10000
#define MAX_TWO 2
char g_str[MAX_NUM]; /* 存储一次满足条件的字符串 */
char g_resStr[MAX_COUNT][MAX_NUM]; /* 存储所有的满足条件的字符串 */
int g_resNum;
void dfs(int index, int leftCount, int rightCount, int num)
{
    /* 终止条件 */
    if (leftCount == num && rightCount == num) {
        if (checkValid(rightCount + leftCount, g_str)) {
            g_str[index] = '\0';
            memcpy(g_resStr[g_resNum++], g_str, sizeof(char) * (rightCount + leftCount));
        }
        return;            
    }
    /*  基于2种可能方向进行dfs */
    if (leftCount < num) {
        g_str[index] = '(';
        dfs(index + 1, leftCount + 1, rightCount, num);
    }
    if (rightCount < num) {
        g_str[index] = ')';
        dfs(index + 1, leftCount, rightCount + 1, num); 
    }
    return;
} 
char ** generateParenthesis(int n, int* returnSize){
    int index = 0;
    g_resNum = 0;
    memset(g_str, '\0' , sizeof(char) * MAX_NUM);
    memset(g_resStr,'\0' , sizeof(char) * MAX_COUNT * MAX_NUM);
    g_str[index++] = '(';
    dfs(index, 1, 0, n);
    char ** ans = malloc(sizeof(char *) * g_resNum);
    for (int i = 0; i < g_resNum; i++) {
        ans[i] = (char *)malloc(sizeof(char) * n * MAX_TWO + 1);
        memcpy(ans[i], g_resStr[i], sizeof(char) * n * MAX_TWO + 1);
    }
    *returnSize = g_resNum;
    return ans;
}
```
