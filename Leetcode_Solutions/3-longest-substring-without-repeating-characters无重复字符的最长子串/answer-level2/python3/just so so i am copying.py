```
def lengthOfLongestSubstring(s: str ) -> int:
    # you题意可知
    # 找出没有重复字符的最常子串
    # 可以利用双指针的方法解决
    # left总指向不重复子串的第一个字符，right指向遍历的最后一个字符
    # right-left+1就是不重复字符的长度
    # 难点在于如何存储以前出现过的字符和更新left(只需要用字典存储出现过的字符的下标即可)
    # left根据right是否出现，并且出现的下标，是否是已经遍历过的了，left不可能更新越小嘛！
    # 因此代码逻辑如下：
    dp = {}
    left, right = 0, 0
    maxv = 0
    for idx, v in enumerate(s):
        if v in dp and dp[ v ] + 1 > left:
            left = dp[ v ] + 1
        dp[ v ] = idx
        maxv = max(maxv, right - left + 1)
        right += 1
    return maxv
```
