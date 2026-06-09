

因为是字母异位，所以需要至少需要遍历完一个字符串，想到保存出现次数，先想到hash，但是hash没有初始key-value，同时让s和t都对一个hash操作有点麻烦，因为需要首先判断字符是否在hash里
于是用一个初始化为0的长度为26个字母的数组进行保存，index对应的是字符的ord值-ord('a')

![image.png](https://pic.leetcode-cn.com/8786e42d9ec1970246c911020dd71be905eb1964f6f6841cd54e2168111107b6-image.png)

初始状态为数组全为0，让s出现的字符都让数组对应index的值+1，t出现的字符都让数组对应的index的值-1，那么如果s和t是两个字母异位的字符串，最终遍历结束这个数组内的所有值都应该还是为0

```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic = {}
        
        for i in s:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
                
        for i in t:
            if i not in dic or dic[i] <= 0:
                return False
            dic[i] -= 1
        
        for i in dic:
            if dic[i] != 0:
                return False
        return True
```


如果字符串包含Unicode字符的话，那还是选择hash表，能够有动态长度，只是需要在s和t对hash处理之后，需要多遍历一次hash，判断内部的value是否均为0了