### 解题思路
此处撰写解题思路

### 代码

```c

int minAddToMakeValid(char * S){
    int iLen = strlen(S);
    if(iLen == 0) return 0;
    if(iLen == 1) return 1;
    char strStack[iLen];
    int top = 0;
    
    int iAddNum = 0;
    for(int i = 0; i < iLen; i++){
        if(S[i] == '('){
            strStack[top] == S[i];
            top++;
        } else {
            if(top == 0) iAddNum++;
            else top--; 
        }
    }
    iAddNum += top;
    
    return iAddNum;
}
```