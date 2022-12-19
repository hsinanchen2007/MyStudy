### 解题思路 1
通过递归的方式解决，因为每次重复，记录当前的长度，然后只需要删除第一个字符，然后继续求删除后的子符子串长度即可
注意递归出口即可。
### 代码
```c
int lengthOfLongestSubstringDF(char *s, int head){
    if(s[head] == '\0') return 0; /*递归出口*/
    int index = head, length = 0;
    int isRepeat = 0;
    for(; s[index] != '\0'; index ++){
        for (int i = head; i < index; i++)
        {
            if(s[i] == s[index]) {
                isRepeat = 1;/* 已经重复了 */
                break;
            }
        };
        if(isRepeat) break;
        else length ++;
    }
    int subLength = lengthOfLongestSubstringDF(s, head + 1);
    return length > subLength?length :subLength;
}

```
### 解题思路2
滑动窗口，大佬们解释得很好了，不累赘了
### 代码
```c
int lengthOfLongestSubstring(char * s){
    int head = 0 ,tail = 0, index = 0 ,length =0;
    for(; s[index] != '\0'; index ++){
        int isRepeat = 0;
        for (int i = head; i < index; i++)
        {
            if(s[i] == s[index]) {
                isRepeat = 1;
                head = index = i + 1;
                break;
            }
        }
        tail = isRepeat == 0 ? tail+1 : 1;
        length = length > tail? length:tail;
    }
    return length;
}
```