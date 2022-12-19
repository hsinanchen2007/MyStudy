### 解题思路

思路简答

1，首先题目说是只有小写字母，那么可以定义一个数组，大小26并全部置为0
2，进行对s字符串遍历，对相应的位置加一
3，进行对t字符串遍历，对相应的位置减一

判断：
最后遍历26个大小的整型数组，如果和初始状态一样全部为0，那么返回true
如果不一样返回false

该方法采用的是遍历，效率不是特别高，但是很容易理解上手
### 代码

```c
bool isAnagram(char * s, char * t){
    int str[26]={0};
    int i,j;
    int length1=strlen(s);
    int length2=strlen(t);
    for(i=0;i<length1;i++)
    {
        str[s[i]-'a']++;//位置字符减‘a’
    }
    for(j=0;j<length2;j++)
    {
        str[t[j]-'a']--;
    }
    for(i=0;i<26;i++)
    {
        if(str[i]!=0)
        return false;
    }
    return true;
}
```