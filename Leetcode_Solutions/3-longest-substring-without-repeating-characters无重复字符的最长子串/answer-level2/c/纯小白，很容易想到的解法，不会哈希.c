### 解题思路
刚开始做，大佬不要嘲笑
我一开始是想每次遇到重复的字符，从他开始再找最长子串，r题目给的特例通过了
错误的例子:
```
abcabcbb
01234567  3和0重复，我从3开始再计数
```

but 提交就出现问题了
想了半天找到了问题，遇到重复的字符，应该从他前一次的下一个开始而不是从新开始
正确的例子:   
```
abcabcbb
01234567  3和0重复，我从1开始再计数
```


### 代码

```c
int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    char zichuan[len+1];
    int temp=0,now=0,j=0,front=0;
    if(*s == ' ')   //特殊情况1
        return 1;
    else if(*s == '\0') //特殊情况2
        return 0;
    while(*s != '\0')
    {
        if(j == 0)  //把第一个字符存进去
        {
            zichuan[j++] = *s;
            s++;
            continue;
        }
        for(int i=front; i<j; i++)  //这里当一个d字符出现第二次时，
        {                           //把front指向前一次出现位置的下一个
            if(zichuan[i] == *s)    //front 和 j之间的长度就是无重复子串
            {
                temp = (temp<(j-front))?(j-front):temp;
                front = i+1;
                break;
            }
        }
        zichuan[j++] = *s;
        s++;
    }
    now = ((j-front)>temp)?(j-front):temp;
    return now;
}
```

![H8FO2BWS~3S223~@)DK\]7W1.png](https://pic.leetcode-cn.com/0b50d56c8a6ebb2bae8c4049234ce76dcc5a9db04527ac6514cf41a549137a56-H8FO2BWS~3S223~@\)DK%5D7W1.png)
