### 解题思路
now一直往后试探，count来更新当前已经数过的单词里面的‘最后一个单词长度’，为了避免句子前后出现的大段空格问题，真的要判断不少呀，自己写的不免有点粗糙。。

### 代码

```c
int lengthOfLastWord(char * s){
    int i=0,count=0,now=0;
    for(i;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            count++;
            now++;
        }
        else
            now=0;
        if(now<count&&now!=0)
        count=now;
    }
    return count;
}
```