### 解题思路
strlen 有些耗时，　


给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.



### 代码

```c
int firstUniqChar(char * s){
    int ht[128] = {0};
    int i=0;

    while (s[i] != '\0') {
            ht[s[i]]++;
            i++;
    }
    i = 0;
    while (s[i] != '\0') {
        if (ht[s[i]] == 1)
            return i;
        i++;
    }
    return -1;
}
```