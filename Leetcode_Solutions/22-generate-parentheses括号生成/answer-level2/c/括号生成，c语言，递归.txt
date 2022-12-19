### 解题思路
左括号个数=右括号个数时：只能添加左括号，
左括号个数>右括号个数时：①添加右括号②如果左括号个数小于n时，复制添加左括号。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void recursion(int n,int i,int j,int k,int* returnSize,char** result){
    if(j<n){
        if(i == j){                             
            result[k][i+j] = '(';
            recursion(n,i+1,j,k,returnSize,result);
        }else{
            result[k][i+j] = ')';
            recursion(n,i,j+1,k,returnSize,result);
            if(i<n){
                result[*returnSize] = (char*)malloc(sizeof(char)*(2*n+1));
                result[*returnSize][2*n] = '\0';
                for(int x=0;x<i+j;x++){
                    result[*returnSize][x] = result[k][x];
                }
                result[*returnSize][i+j] = '(';
                (*returnSize)++;
                recursion(n,i+1,j,(*returnSize)-1,returnSize,result);
            }
        }
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char** result = (char**)malloc(sizeof(char*)*5000);
    result[0] = (char*)malloc(sizeof(char)*(2*n+1));
    result[0][2*n] = '\0';
    result[0][0] = '(';
    *returnSize = 1;
    recursion(n,1,0,0,returnSize,result);
    return result;
}
```

或者弄一个打工仔临时变量temp来实现递归
```
void recursion(int n,int i,int j,char* temp,int* returnSize,char** result){
    if(j<n){
        if(i<n){
            temp[i+j] = '(';
            recursion(n,i+1,j,temp,returnSize,result);
        }
        if(i>j){
            temp[i+j] = ')';
            recursion(n,i,j+1,temp,returnSize,result);
        }
    }else{
        result[*returnSize] = (char*)malloc(sizeof(char)*(2*n+1));
        result[*returnSize][2*n] = '\0';
        for(int i=0;i<2*n;i++){
            result[*returnSize][i] = temp[i];
        }
        (*returnSize)++;
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char** result = (char**)malloc(sizeof(char*)*5000);
    *returnSize = 0;
    char* temp = (char*)malloc(sizeof(char)*2*n);
    recursion(n,0,0,temp,returnSize,result);
    free(temp);
    return result;
}
```
