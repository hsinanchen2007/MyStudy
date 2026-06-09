这道题没啥难点，只需要注意两个问题。
1.考虑到整个字符串由字母和空格组成，我们仅仅需要计算最后一个单词的长度（如果存在），那么我们需要考虑结尾是空格的情况，所以第一步我们需要消去空格。
2.在第一步的基础上，如果我们再次遇到空格，毫无疑问肯定就是一个单词的结束了。
```
int lengthOfLastWord(char * s){
    int length=strlen(s);//得到数组长度
    int i,count=0;
    while(length>0&&s[length-1]==' ')//去掉空格部分
    length--;
    for(i=length-1;i>-1;i--)
    {
        if(s[i]!=' ')
        count++;
        else
        return count;
    }
    return count;
}
```
