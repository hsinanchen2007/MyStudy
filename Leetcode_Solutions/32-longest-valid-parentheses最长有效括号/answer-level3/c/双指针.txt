### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a, b) (a) > (b) ? (a) : (b)
int longestValidParentheses(char * s){
    int sLen = strlen(s);

    /* 输入有效性 */
    if ((s == NULL) || (sLen <= 1)) {
        return 0;
    }

    int* idxBuff = (int *)malloc(sizeof(int) * sLen);

    int rslt = 0;
    int leftIdx  = -1;
    int rightIdx = 0;
    int top = -1;

    for (rightIdx = 0; s[rightIdx] != '\0'; rightIdx++) {
        if (s[rightIdx] == '(') {
            /* 当遇到左括号时，入栈，栈顶加1 */
            top++;
            idxBuff[top] = rightIdx;
        } else if (s[rightIdx] == ')') {
            if (top == -1) {
                 /* 当遇到右括号，且栈内元素为空时，此时左括号的个数小于右括号的个数，更新leftIdx，重新开始计数 */
                leftIdx = rightIdx;
            } else {
                top--; /* 出栈 */

                if (top == -1) {
                    rslt = MAX(rightIdx - leftIdx, rslt);
                } else {
                    /* 栈不为空，还有未匹配的符号 */
                    rslt = MAX(rightIdx - idxBuff[top], rslt);
                }
            }
        }
    }
    return rslt;
}
```