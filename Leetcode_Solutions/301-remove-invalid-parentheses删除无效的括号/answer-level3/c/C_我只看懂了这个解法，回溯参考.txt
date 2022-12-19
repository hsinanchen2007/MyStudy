### 解题思路
回溯算法
1.如果要平衡空格数量肯定要相等，刚开始统计左右空格分别多的数目。
2.然后进行回溯，当平衡是记录结果。
3.否则遍历字符串删除碰到多余的就删除进行测试。
4.如果遍历是遇到相同的跳过避免重复。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int gResultSize = 0;
char **gResult;
bool IsValid(char *s){
    int cnt = 0;
    char *p = s;
    while (*p != '\0') {
        if (*p == '(') {
            cnt++;
        }
        else if (*p == ')') {
            cnt--;
        }
        if (cnt < 0) {
            return false;
        }
        p++;
    }
    return cnt == 0;
}

void removeInvalidParentheses2(char * s, int sLen , int start, int leftCnt, int rightCnt){
    if (start > sLen) {
        return;
    }
    //printf("enter:%s :%d:%d:%d\n", s, start, leftCnt, rightCnt);
    if (leftCnt == 0 && rightCnt == 0) {
        //printf("wait:%s\n", s);
        if (IsValid(s)) {
            gResult[gResultSize] = malloc(sizeof(char) * sLen + 1);
            strcpy(gResult[gResultSize], s);
            gResultSize++;
            //printf("%s\n", s);
        }
        return;
    }
    char subStr[sLen];
    for (int i = start; i < sLen; ++i) {
        if (i > start && s[i] == s[i - 1]){
            continue;
        }
        if (s[i] == '(' && leftCnt > 0){
            memcpy(subStr, s, i);
            subStr[i] = '\0';
            strcat(subStr, s + i + 1);
            removeInvalidParentheses2(subStr, sLen - 1, i, leftCnt - 1, rightCnt);
        } else if (s[i] == ')' && rightCnt > 0){
            memcpy(subStr, s, i);
            subStr[i] = '\0';
            strcat(subStr, s + i + 1);
            //printf("subStr-->%s\n", subStr);
            removeInvalidParentheses2(subStr, sLen - 1, i, leftCnt, rightCnt - 1);
        }
    }
}
#define MAX_RESULT_LEN 10000
char ** removeInvalidParentheses(char * s, int* returnSize){
    int leftCnt = 0;
    int rightCnt = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '(') {
            leftCnt++;
        } else if (s[i] == ')'){
            if (leftCnt == 0){
                rightCnt++;
            } else {
                leftCnt--;
            }
        }
    }
    char **ans = malloc(sizeof(char*) * MAX_RESULT_LEN);
    memset(ans, 0, sizeof(char*) * MAX_RESULT_LEN);
    gResult = ans;
    gResultSize = 0;
    removeInvalidParentheses2(s, strlen(s), 0, leftCnt, rightCnt);
    //printf("%d\n", gResultSize);
    if (gResultSize == 0){
        gResult[0] = "";
        gResultSize = 1;
    }
    *returnSize = gResultSize;
   
    return ans;
}

```