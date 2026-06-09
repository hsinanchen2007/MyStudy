### 解题思路
好吧，发现一年前这种题目都不会写。。。
分类讨论一下：三种情况，符合某一种，就是正确的，否者就是不正确的

### 代码

```c
bool detectCapitalUse(char * word){
    int len;
    int i=0;
    len=strlen(word);
    if(len==0||len==1){
        return true;
    }
    while(i<len&&word[i]>='A'&&word[i]<='Z'){
        i++;
    }
    if(i==len){
        return true;
    }
    i=1;
    while(i<len&&word[i]>='a'&&word[i]<='z'){
        i++;
    }
    if(i==len){
        return true;
    }
    return false;
}
```