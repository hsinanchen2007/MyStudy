### 解题思路
判断s是不是t的子序列，t的长度必须大于s的长度
在母串t中从头到尾先找子串s的第一个字符，找到之后，在母串剩下的字符中再找子串的第二个字符，一直到母串没有字符可以查找。如果已经对比到子串最后一个字符，就说明s是t的子串。
题目说明了，子串的字符在母串中的顺序不会改变，所以可以通过一次遍历母串就能得到结果

### 代码

```c
bool isSubsequence(char * s, char * t){
    int Slength=0,Tlength=0;
    for(char* iter=s;*iter!='\0';++iter)++Slength;
    for(char* iter=t;*iter!='\0';++iter)++Tlength;

    if(Slength>Tlength)return false;

    for(int i=0;i<Tlength;++i)
        if(*s==t[i])
            ++s;
    return *s=='\0';
}
```