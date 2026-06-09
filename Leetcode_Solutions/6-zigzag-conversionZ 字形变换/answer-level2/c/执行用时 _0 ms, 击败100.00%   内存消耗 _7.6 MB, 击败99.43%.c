### 解题思路
    用含numRows式子表示每一行的s下标，一行一行输入ans中
### 代码

```c


char * convert(char * s, int numRows){
    int len=strlen(s),j=0,t=2*numRows-2;
    static char ans[1000]={'\0'};
    for(int i=0;i<1000;i++)
        ans[i]='\0';
    if(len==0||numRows==0)
        return ans;
    if(len==1||numRows==1||len<=numRows)
    {    strcpy(ans,s);
        return ans;}
    for(int i=0;i<len;i=i+t)   //输出第一行
        ans[j++]=s[i];
    for(int r=2;r<=numRows-1;r++)    //输出中间
    {
        ans[j++]=s[r-1];
        for(int i=r-1+t-2*(r-1);i<len;)
        {
            ans[j++]=s[i];
            i=i+2*(r-1); 
            if(i<len)
                ans[j++]=s[i];
            else
                break;
            i=i+t-2*(r-1);
        }
    }
    for(int i=numRows-1;i<len;i=i+t)   //输出最后一行
        ans[j++]=s[i];
    return ans;
}


```