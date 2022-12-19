这里不知道有么有考研党的，我记得在王道天勤还有各个院校的考题中应该是出过这种类似的题。

当时要求的是用栈来实现。当时书上的题应该是把前缀表达转后缀表达，思路是一致的。

所以我这里的基本思路是用栈来做的，大概讲一下，当坐括号出现的时候必定要期待相应的右括号，右括号出现就会消除栈里面的相邻的左括号，如果左边不是那么必将匹配失败。

所以得出结论，我们只需要判断右括号出现，栈里面是不是有相应的左括号，然后用栈顶指针依次消除，最后判断一下栈

顶指针的位置即可。

这里说明一下，栈的指针的位置到底是指针当前元素还是待插入元素的位置需要注意一下。
```
bool isValid(char * s){
    int length=strlen(s);//获取字符长度
    if(length==0)//别用'\0'判断
    return true;
    char *mark=(char *)malloc(sizeof(char)*length);//建立一个标记数组
    int i,count=-1;
    for(i=0;i<length;i++)
    {
        if(*(s+i)==')')
            if(count>-1&&*(mark+count)=='(')
            count--;
            else 
            return false;
        else if(*(s+i)=='}')
            if(count>-1&&*(mark+count)=='{')
            count--;
            else 
            return false;
        else if(*(s+i)==']')
            if(count>-1&&*(mark+count)=='[')
            count--;
            else 
            return false;
        else
            mark[++count]=s[i];
    }
    if(count>-1)
    return false;
    return true;
}
```
