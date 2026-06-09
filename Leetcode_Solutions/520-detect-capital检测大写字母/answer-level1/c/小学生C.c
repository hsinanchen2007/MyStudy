### 解题思路
字符串中每一个字母，大写为1，小写为0，通过循环遍历后，可以得出该字符串的值。
题目三种格式才判断为正确，把三种格式分解为2个判断，首字母大写和小写，首字母大写时，当值为字符串长度时，即全部大写，当值等于1时，即首字母大写，后面全小写。
首字母小写时，当值等于0时，说明全小写，返回true ，其他默认返回false

### 代码

```c
bool detectCapitalUse(char * word){
    int i=0,a=0;
    while(word[i]!=NULL)
    {
        if(word[i]>='A'&&word[i]<='Z')
            a=a+1;
        if(word[i]>='a'&&word[i]<='z')
            a=a+0;
        i++;
    }
    if(word[0]>='A'&&word[0]<='Z'){
        if(i==a||a==1)
            return true;
    }
    if(word[0]>='a'&&word[0]<='z'){
        if(a==0)
            return true;
    }
    return false;
}
```