大家首先先了解一下回文数：数关于某一条轴是堆成的，比如说：
```
    |                           |
a b | b a          或者       a b a
    |                           |    
```
我们可以发现只需要找到轴，然后依次判断两边的值是否对称即可。

这里还是会有问题：奇数和偶数的判断是不同的，那么我们是否可以统一化呢？
答案是可以的，细心观察，对于任何N个字符，比如说：
```
_a_b_c_c_b_a_ 我们可以发现，N个数会有N+1个空
```
我们可以在N+1个空中填入相同的字符
```
 #a#b#c#c#b#a#
```
这样我们就可以统一化奇数和偶数的情况




```
char * longestPalindrome(char * s){
    int posi,count=0,i,j,length=strlen(s);
    char *mark=(char *)malloc(sizeof(char)*(2*length+3));
    length=length*2+2;
    memset(mark,'#',length+1);//一个位置留给结束符
    mark[length]='\0';//字符串结尾符
    mark[0]='$';
    for(i=2,j=0;i<length;i+=2,j++)//初始化字符
        mark[i]=s[j];
    for(i=1;i<length;i++)//开始求步长和驻点
    {
        for(j=1;i+j<length;j++)
        {
            if(mark[i-j]!=mark[i+j])//两者不相等
            break;
        }
        if(2*j-1>count)
        {
            count=2*j-1;//得到字符串的总长度
            posi=i;
        }        
    }
    for(i=posi-count/2+1,j=0;i<posi+count/2;i+=2,j++)
    {
        s[j]=mark[i];
    }
    s[j]='\0';
    return s;
    
}
```
