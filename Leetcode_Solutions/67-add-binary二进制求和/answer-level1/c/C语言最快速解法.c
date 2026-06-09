看到好多解法里先将两个字符串当中较短的一个进行补齐，其实挺耗时间的...可以使用最长的字符串的长度作为大循环的判断条件，每次运算后储存两个字符串长度的变量减一，若是有一个小于0后就只用另一个

运行时间接近0ms，就是空间用的多了一些（不过就我个人看来其实空间无所谓，速度才是最重要的）

![QQ截图20191101195612.png](https://pic.leetcode-cn.com/d8826e8db0a188916af445ff8569bcd01ac023e9ee9d2b1a5c3351782c2bad6f-QQ%E6%88%AA%E5%9B%BE20191101195612.png)

话不多说，上代码：


char * addBinary(char * a, char * b){
    int l1=strlen(a);
    int l2=strlen(b);
    int l=(l1>l2?(l1+1):(l2+1));
    int temp;
    char *ch=(char*)malloc((l+5)*sizeof(char));
    memset(ch,0,(l+5)*sizeof(char));
    int pd1,pd2;
    l1--;
    l2--;
    int i;
    for(i=l-1;i>=0;i--)
    {
        if(l1>-1)
            pd1=1;
        else
            pd1=0;
        if(l2>-1)
            pd2=1;
        else
            pd2=0;
        if(pd1&&pd2)
            ch[i]+=a[l1]+b[l2]-48;  //48 is '0'
        else if(pd1)
            ch[i]+=a[l1];
        else if(pd2)
            ch[i]+=b[l2];
        else
        {
            if(ch[i]>1)
            {
                ch[i]-=48;
                temp=ch[i]/2;
                ch[i]%=2;
                ch[i]+=48;
                i--;
                ch[i]+=temp;
            }
            ch[i]+='0';
            break;   
        }    
        if(ch[i]>1)
        {
            ch[i]-=48;
            temp=(ch[i])/2;
            ch[i]%=2;
            ch[i-1]+=temp;
            ch[i]+=48;
        }
        l1--;
        l2--;
    }
    for(;i<l;i++)
        if(ch[i+1]==0)
            break;
        else if(ch[i]=='0'&&ch[i+1]!=0)
            ch[i]=0;
        else
            break;
    return ch+i;
}

