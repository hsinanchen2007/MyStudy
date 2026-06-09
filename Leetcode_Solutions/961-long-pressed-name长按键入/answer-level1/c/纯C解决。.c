题目很简单，题意就是告诉你，你原本就是想输入一个人的姓名，但是可能会出现某个字母重复按的情况。也就是说你可

以对于某个字符多按几次。也就是说次序不能变，不能少按，也不能多按其他的字母。

那么思路就相当清爽了。同时遍历两个数组，要么相等，要么不相等。

相等就很简单，同时向后推进。

不相等，你需要考虑是不是按了其他多余的字符，或者是不是多按的，多按的就没有关系。

还有就是要考虑一下首个字符就不相等的极端情况。
```
bool isLongPressedName(char * name, char * typed){
    int length1=strlen(name),length2=strlen(typed);
    int i=0,j=0;
    while(i<length1||j<length2)
    {
        if(name[i]!=typed[j])
        {
            if(i==0)
            return false;
            if(typed[j]==name[i-1])
            j++;
            else 
            return false;
        }
        else{
            i++;j++;
        }
    }
    if(i==length1&&j==length2)
    return true;
    return false;
}
```
