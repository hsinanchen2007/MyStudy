### 解题思路
括号的配对性构成天然的入栈和出栈，难以想到的是构造一个无效的括号栈，参考“[就是一个Stack，局部优化](https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/solution/jiu-shi-yi-ge-stackju-bu-you-hua-by-puckchen/)”学习到了。

栈的内容是括号所处的位置。
栈形成后再构造输出字符串，跳过栈中的内容，这里是把构建好的栈当成队列用（FIFO）。
### 代码

```c
#define PRINTF //printf
char * minRemoveToMakeValid(char * s){
    int numOpenPath = 0;
    int numClosePath = 0;
    int len = strlen(s);
    int *pRemStack = (int *)malloc((len + 1) * sizeof(int)); //构建一个栈，栈中保存需要移除的位置
    if(pRemStack == NULL){
        goto ERR;
    }
    int sSize = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '('){
            PRINTF("Push:%d %d", sSize, i);
            pRemStack[sSize] = i;
            sSize++;
            continue;
        }
        if(s[i] == ')'){
            if((sSize > 0) && (s[pRemStack[sSize - 1]] == '(')){ //将有效括号待移除的栈
                PRINTF("Pop:%d %d", pRemStack[sSize - 1], i);
                sSize--; //弹栈，用栈的长度控制有效性
            }else{
                PRINTF("Push:%d %d", sSize, i);
                pRemStack[sSize] = i;
                sSize++;
            }
            continue;
        }
    }
    int rSize = 0;
    int sPopSize = 0;
    char *pRetStr = (char *)malloc((len + 1 - sSize) * sizeof(char));
    if(pRetStr == NULL){
        goto ERR;
    }
    for(int i = 0; i < len; i++){
        if((sPopSize < sSize) && (pRemStack[sPopSize] == i)){
            PRINTF("Pop:%d %d %d",sSize, pRemStack[sPopSize], i);
            pRemStack[sPopSize] == -1;
            sPopSize++;
        }else{
            pRetStr[rSize] = s[i];
            rSize++;
        }
    }
    pRetStr[rSize] = 0; //结束符
    free(pRemStack); //释放移除栈
    return pRetStr;
ERR:
    if(pRetStr != NULL){
        free(pRetStr);
    }
    if(pRemStack != NULL){
        free(pRetStr);
    }
    return NULL;
}
```