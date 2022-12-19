### 解题思路
使用双指针法遍历字符串s和t，当字符相同时，指针都往后移一位；当不同时，指向t的指针后移一位。

### 代码
方法一：
```c
bool isSubsequence(char * s, char * t){
    if(!s||!t)
        return false;
    int i = 0, j = 0;
    int len_s = strlen(s);
    int len_t = strlen(t);
    while(i<len_s && j<len_t)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    if(i==len_s)
        return true;
    return false; 
}
方法二：看了大佬的思路，更简洁，方法一的优化。
bool isSubsequence(char * s, char * t){
    while (*s && *t) 
    {
        if (*s == *t) 
            s++;
        t++;
    }
    if (*s == '\0')
        return true;
    return false;
}
```