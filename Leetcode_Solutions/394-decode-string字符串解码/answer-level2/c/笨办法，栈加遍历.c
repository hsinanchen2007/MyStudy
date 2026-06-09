### 解题思路
压栈，遇到[解析字符串，在压回去，继续遍历。

### 代码

```c
int Push(char *stack, char *str, int len, int count)
{   
    for(int i = 0; i < count; i++) {
        strncat(stack, str, len);
    }
    return strlen(stack);;
}

char * decodeString(char * s){
    char *stack  = NULL;
    char *cur = NULL;
    char tmpChr[1000] = {'\0'};
    int len = strlen(s);
    int top;
    int chrNum[128] = {'\0'};
    int number;
    if (len == 0) {
        return "";
    }
    stack = (char*)malloc(10000 * sizeof(char));
    memset(stack, 0, 10000 * sizeof(char));
    //retarr = (char*)malloc()
    cur = s;
    top = -1;
    number = 0;
    for(int i = 0; i < len; i++) {
        if (cur[i] == ']') {
            // 出栈
            //printf("pop\n");
            int subLen = 0;
            int count = 0;
            number = 0;
            memset(chrNum, 0, 128);
            for (int j = top; j >= 0 ; j--) {
                //printf(" %c",stack[j]);
                if (stack[j] != '[') {
                    subLen++;
                } else {
                    break;
                }
            }
            for (int j = top - subLen - 1; j >= 0; j--) {
                if(stack[j] <= '9' && stack[j] >= '0') {
                    number++;
                } else {                   
                    break;
                }
            }
            strncpy(chrNum, stack+(top-subLen-number), number);
            //printf("chr %s, st %s",chrNum,stack+(top-subLen-number));
            count = atoi(chrNum);
            //printf("\nnumber %d char %s stack:%s\n",number, chrNum, stack);
            strncpy(tmpChr, stack+(top-subLen)+1, subLen); 
            //printf("stack: %s, tmpchr: %s len %d count %d\n",stack,tmpChr,subLen,count);            
            for(int n = 0; n < subLen+number+1; n++) {
                stack[top-n] = '\0';
            }   
               
            top = Push(stack, tmpChr, subLen, count) - 1;
            //printf("current stack: %s\n",stack);           
        } else {
            // 压栈
            top++;
            stack[top] = cur[i];     
            //printf("push %s i %d, top %d\n",stack,i,top);
        }
    }
    
    return stack;
}
```