### 解题思路
此处撰写解题思路

### 代码

```c
char * removeOuterParentheses(char * s){
    int i,k;
    int count1=0;
    int count2=0;
    int j=0;
    k=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(')
            count1++;
        if(s[i]==')')
            count2++;
        if(count1==count2)
        {
            for(int m=j+1;m<i;m++)
                s[k++]=s[m];
            j=i+1;
            count2=0;
            count1=0;
        }
 
    }
    for(int m=k;m<strlen(s);m++)
        s[m]='\0';
    return s;

}
```