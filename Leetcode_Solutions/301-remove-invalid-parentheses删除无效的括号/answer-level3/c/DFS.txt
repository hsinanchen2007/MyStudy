### 解题思路
DFS
1、求出 最少删除多少左括号和右括号，才能构成有效括号对，这里用计数器实现；
2、定义STEP，每次删除一个左括号（如果需要删除的左括号大于0）和一个右括号（如果需要删除的右括号大于0）；
3、定义OPTION，从输入的字符串s里面，遍历执行上面的STEP，下次遍历从当前遍历的位置开始（因为前面已经完成遍历）。
void DFS_GetS(char **retc, char *s, int start, int left, int right)
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 1000
int g_returnSize;
int g_returnSlen;

void GetS(char *s, int *left, int *right)
{
    int i = 0;
    int left_tmp = 0;
    int right_tmp = 0;
    while(*(s + i) != '\0') {
        if (*(s + i) == '(') {
            left_tmp = left_tmp + 1;
        } else if (*(s + i) == ')') {
            if (left_tmp > 0) {
                left_tmp--;
            } else {
                right_tmp++;
            }
        }
        i++;
    }
    *left = left_tmp;
    *right = right_tmp;
}
bool CheckS(char *s)
{
    int i = 0;
    int left_tmp = 0;
    while(*(s + i) != '\0') {
        if (*(s + i) == '(') {
            left_tmp = left_tmp + 1;
        } else if (*(s + i) == ')') {
            if (left_tmp > 0) {
                left_tmp--;
            } else {
                return false;
            }
        }
        i++;
    }
    if (left_tmp > 0) {
        return false;
    }
    return true;
}
void DelC(char *tmp, int index, int len)
{
    for(int i = index + 1; i < len; i++) {
        tmp[i - 1] = tmp[i]; 
    }
    tmp[len - 1] = '\0';
}
void DFS_GetS(char **retc, char *s, int start, int left, int right)
{
    if (left == 0 && right == 0) {
        if (CheckS(s) == false) {
            return;
        }
        retc[g_returnSize] = (char *)malloc(sizeof(char) * g_returnSlen);
        strcpy(retc[g_returnSize], s);
        g_returnSize++;
    }
    char tmp[MAX] = {0};
    int len = strlen(s);
    for (int i = start; i < len; i++) {
        if (i > 0 && s[i] == s[i - 1]) {
            continue;
        }
        strcpy(tmp, s);
        if (left > 0 && s[i] == '(') {
            DelC(tmp, i, len);
            printf("( %d %s\n", i, tmp);
            DFS_GetS(retc, tmp, i, left - 1, right);
        }
        if (right > 0 && s[i] == ')') {
            DelC(tmp, i, len);
            printf(") %d %s\n", i, tmp);
            DFS_GetS(retc, tmp, i, left, right - 1);
        }
    }
}
char ** removeInvalidParentheses(char * s, int* returnSize)
{
    int len = strlen(s);
    int left, right;
    GetS(s, &left, &right);
    g_returnSlen = len - (left + right) + 1;
    char **retc = (char **)malloc(sizeof(char *) * MAX);
    if (g_returnSlen == 1){
        *returnSize = 1;
        *retc = "";
        return retc;
    }
    g_returnSize = 0;
    DFS_GetS(retc, s, 0, left, right);
    *returnSize = g_returnSize;
    return retc;
}
```