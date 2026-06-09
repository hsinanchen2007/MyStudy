该方法的实质是对KMP算法的一个应用，更准确一点的话就是对next数组的应用。

这里大概讲一下相关知识，next数组的本质就是算一个字符串中相同的前后缀。

这里其实是有一个式子的：next[length]=length-strlen(X)(X为最小周期子串)(next数组是右移之后的数组)

看了网上很多关于这个式子的帖子，基本上都是一笔带过，我自己手动推了一下。

先举个例子，比如说：abababab

很明显，ab是最小周期子串，对于ab而言，缺少那个都不能组成一个周期串，并且顺序也不能改变。

next[length]的公共前后缀长度为6(这里先是利用人工算出来的)

接下来推导一下next[length]=length-strlen(X)

我们在算前缀的时候，末尾b的前缀 分别有：a,ab,aba,abab,ababa,ababab,abababa

开头a的后缀：b,ab,bab,abab,babab,ababab,bababab

其实这里的a,b都是属于最小周期串的，并且位置不同，如果他们不存在了，必然相邻能够组成最小周期串的其他字符也

无法成为公共前后缀了。因此，前缀中的以a结尾，后缀中以b结尾的都不能够成为公共前后缀。

前缀中以b结尾（丢了一个a）,后缀中以a结尾（丢了一个b）都能够成为公共前后缀。

因此next[length]=length-strlen(X)可以得到。

length-next[length]是最小周期长度易知。

这里如果想更清楚，强力建议看一下next[i]是如何根据next[i-1]如何推导过来的。

以上内容写得有点儿复杂，如果有大神有更好的推导过程欢迎留言讨论~不懂的也欢迎留言~~

```
void CalcNext(char *p,int *next)
{
    next[0]=-1;
    int nlen=strlen(p);
    int k=-1;
    int j=0;
    while(j<nlen)
    {
        if(k==-1||p[j]==p[k])
        {
            ++k;++j;
            next[j]=k;
        }
        else
        k=next[k];
    }
}
bool repeatedSubstringPattern(char * s){
    int length=strlen(s);
    int *next=(int *)malloc(sizeof(int)*(length+1));
    CalcNext(s,next);
    int k=next[length];
    int p=length-k;
    if(length%p==0&&length!=p)
    return true;
    return false;
}
```
