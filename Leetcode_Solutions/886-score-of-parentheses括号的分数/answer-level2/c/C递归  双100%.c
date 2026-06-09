### 解题思路
判断字符串类型，为()时返回1，为(A)返回2*递归A   为AB时返回递归A+递归B

### 代码

```c
int scoreOfParentheses(char * S){
    int i,j,k=0;
    int len = strlen(S);
    char P[50];
    int ans;
    //puts(S);
    if(len == 2)
        return 1;
    for(i=0;i<len;i++)
    {
        if(S[i] == '(') k += 1;
        else k -= 1;

        if((k == 0) && (i != (len-1)))  /* AB */
        {
            for(j=0;j<=i;j++) P[j]=S[j];
            P[j] ='\0';
            ans= scoreOfParentheses(P) + scoreOfParentheses(S+i+1);
            //printf("   %d   ",ans);
            return ans;
            
        }
        else if((k == 0) && (i == (len-1)))     /* A */
        {
            for(j=1;j<len-1;j++) P[j-1]=S[j];
            P[j-1] ='\0';
            return (scoreOfParentheses(P) * 2);
        }
    }
    return 0;
}
```