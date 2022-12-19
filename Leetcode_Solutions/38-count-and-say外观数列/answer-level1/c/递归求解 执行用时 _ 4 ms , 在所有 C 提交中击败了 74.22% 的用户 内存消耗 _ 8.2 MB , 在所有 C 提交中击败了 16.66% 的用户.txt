```
#define Len 4500
char * countAndSay(int n){
    char *pre, *num;
    int i=1;
    int len=0;
    int m=0;
    char flag;
    int index=0;
    pre = (char *)malloc(sizeof(char) * Len);//保存当前字符串
    num = (char *)malloc(sizeof(char) * Len);//保存上一层字符串 
    if(n==1)
        return "1";
    else
    {
        num=countAndSay(n-1);//求出上一层字符串
        len=strlen(num);//求出上一层字符串长度
        flag=num[0];//标记字符为第一个字符
        m=1;//记录标记字符的个数
	    while(i<len)//向后遍历
        {
            if(num[i]==flag)//如果当前字符和标记字符一样
                m+=1;//个数加一
            else//如果当前字符和标记字符不一样
            {
                pre[index++]=m+'0';//将此次遍历结果写入结果字符串中
                pre[index++]=flag;
                m=1;//修改个数
                flag=num[i];//修改标记字符为当前字符
            }
            i+=1;
	   }
	   pre[index++]=m+'0';//将最后一次遍历结果写入字符串中
       pre[index++]=flag;
       pre[index]='\0';
       return pre;
    }
}

```
