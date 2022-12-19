这道题最大的问题就是读题.....开始看了半天，再看看难度。简单？？？开始怀疑能力，然后喝了两口水冷静一

下，最后怀疑的是自己的眼神。。。子序列！！不是子串！！！也就是说只要相对位置不变就行。举个例子。

abbbbaaa,取出aaaa，这也是一个子序列。

题目很简单，这么一分析就肯定最多不会超过2了，因为只有a和b，那么我们最多，第一次删除a，第二次删除b。

一次的情况很简单，那肯定就是回文串才能一次了。

直接上代码：
```
int removePalindromeSub(char * s){
    int length=strlen(s);
    if(length==0)
    return 0;
    int low=0,high=length-1;
    while(low<high)
    {
        if(s[low]!=s[high])
        return 2;
        low++;
        high--;
    }
    return 1;
}
```
