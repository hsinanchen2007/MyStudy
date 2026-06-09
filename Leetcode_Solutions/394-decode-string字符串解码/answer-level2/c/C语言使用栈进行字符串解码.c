```c
char * decodeString(char * s){
    int len = strlen(s);
    
    int stackSize = 50;
    char* stack = (char*)malloc(stackSize * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < len; ++i) {
        if (s[i] != ']') {
            if (top == stackSize - 1) {
                stack = realloc(stack, (stackSize += 50) * sizeof(char));
            }
            stack[++top] = s[i];
        }
        else {
            int tempSize = 10;
            char* temp = (char*)malloc(tempSize * sizeof(char));
            int topOfTemp = -1;
            while (stack[top] != '[') {
                if (topOfTemp == tempSize - 1) {
                    temp = realloc(temp, (tempSize += 10) * sizeof(char));
                }
                temp[++topOfTemp] = stack[top--];
            }
            char strOfInt[11];
            int p = top--;
            while (top != -1 && stack[top] >= '0' && stack[top] <= '9') {
                top--;
            }
            for (int j = top + 1; j < p; ++j) {
                strOfInt[j - (top + 1)] = stack[j];
            }
            strOfInt[p - (top + 1)] = '\0';
            for (int k = 0; k < atoi(strOfInt); ++k) {
                int kk = topOfTemp;
                while (kk != -1) {
                    if (top == stackSize - 1) {
                        stack = realloc(stack, (stackSize += 50) * sizeof(char));
                    }
                    stack[++top] = temp[kk--];
                }
            }
            free(temp);
            temp = NULL;
        }
    }
    char* ans = realloc(stack, (top + 2) * sizeof(char));
    ans[++top] = '\0';
    return ans;
}
```
