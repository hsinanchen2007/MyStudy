定义：
![批注 2019-10-16 112144.png](https://pic.leetcode-cn.com/1c1b0051e7e80c24af23e5069361e90a9d04db1996a2c7be898f1449864d7746-%E6%89%B9%E6%B3%A8%202019-10-16%20112144.png)

kmp 什么的先往后稍稍，这里推荐效率爆炸的 sunday 算法，这里只讨论如何在当前字符串不匹配的时候计算下一个检查匹配的下标

- 如果匹配区间的下一个字符不在模式串中，则匹配区间直接移动到这个字符后面去
- 否则，移动偏移表中指定的长度

关于偏移表的生成
模式串中每一个字符对应一个数值，这个数值的生成方法如下
- 字符在模式串中，则偏移量为该字符靠近模式串结尾距离的最小值加一
- 剩下所有字符的偏移量都为字符串长度+1
```cpp
for (size_t i = 0; i < lenNeedle; i++)
    buf[needle[i]] = lenNeedle-i;
```

这里用到的思想很朴素，如果匹配区间后面的一个字符不在模式串中，那么最终答案的匹配区间必然不会包含这个字符，跳过去就好了。  
如果匹配区间后面一个字符在模式串中出现，那么就让模式串结尾起最先出现的这个字符与其对应，防止漏掉任何可能的答案，我觉的这里应该还能加速，因为移动前的匹配区间很可能与移动后的有重合，那些字符被重复扫描了，所以如果能跳过那些重复扫描的字符，速度也许能更快

```cpp
int strStr(string haystack, string needle) {
    if(needle.empty()) return 0;
    unordered_map<char,size_t> buf;
    size_t len = haystack.size();
    size_t lenNeedle = needle.size();

    for (size_t i = 0; i < lenNeedle; i++)
        buf[needle[i]] = lenNeedle-i;
    
    for (size_t i = 0; i < len;)
    {
        size_t j;
        for (j = 0; j < lenNeedle; j++)
            if(haystack[i+j] != needle[j]) break;
        if(j == lenNeedle) return i;
        if(i+lenNeedle >= len) return -1;
        else i += buf.count(haystack[i+lenNeedle]) ? buf[haystack[i+lenNeedle]] : lenNeedle+1;
    }
    return -1;
}
```