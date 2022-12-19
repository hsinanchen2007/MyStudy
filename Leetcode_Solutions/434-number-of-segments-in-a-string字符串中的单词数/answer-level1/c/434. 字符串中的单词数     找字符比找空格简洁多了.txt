### 解题思路
有新字符就加1



统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5



### 代码

```c
int countSegments(char * s){
    int cnt = 0, i = 0;

    while (s[i] != '\0') {
        if (s[i] != ' ') {
            cnt++;
            while(s[i] != ' ' && s[i] != '\0')   i++;
        } else
            i++;
    }
  
    return cnt;
}
```