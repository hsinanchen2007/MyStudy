### 解题思路
此处撰写解题思路

### 代码

```c
char ans[1000];
char * convert(char * s, int numRows){
    
    int len_ans = 0, len_s = strlen(s);
    int i,j,k;
    if(numRows == 1) return s;
    for(j=0,i=0;i<len_s;j++)     //第一行
    {
    	i=j*(2*numRows-2);
    	if(i<len_s)
        	ans[len_ans++] = s[i];
    }
    
    for(k=1;k<numRows-1;k++)                 //2 ~ n-1行
    {
        for(j=0;;j++)                          
        {
            i=j*(2*numRows-2)+k;
            if(i>=len_s) break;
            ans[len_ans++]=s[i];

            i+=2*numRows-2*k-2;
            if(i>=len_s) break;
            ans[len_ans++]=s[i];
        }
    }

    for(j=0;numRows+j*(2*numRows-2)-1<=len_s;j++)     //第n行
    {
        ans[len_ans++] = s[numRows+j*(2*numRows-2)-1];
    }

    ans[len_ans]='\0';
    return ans;
}
```