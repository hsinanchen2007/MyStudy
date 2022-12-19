
分析过程可以参看LeetCode官方题解，这里提供其Python3写法 [LeetCode题解](https://leetcode-cn.com/problems/longest-common-prefix/solution/zui-chang-gong-gong-qian-zhui-by-leetcode/)



1. 水平扫描

```
class Solution(object):
    def longestCommonPrefix(self, strs: list) -> str:
        if not len(strs):  # 如果传入的list本身就是空的 直接返回空
            return ""
        prefix = strs[0]  # 设置第1个字符串为默认最长公共前缀
        for i in range(1, len(strs)):  # 第0个就不用匹配了，从第1个开始一直匹配到第len(strs)个
            while strs[i].find(prefix) != 0:  # 用这句话判断当前prefix是不是也是其他字符串的前缀
                prefix = prefix[:-1]  # 减少前缀
                if not prefix:  # 当 prefix为空时，匹配不成功，直接返回""。
                    return ""
        return prefix
```

2. 垂直扫描
```
class Solution(object):
    def longestCommonPrefix(self, strs: str) -> str:
        if not len(strs):  # 如果传入的list本身就是空的 直接返回空
            return ""
        for i in range(len(strs[0])):  # 遍历strs[0]的所有字符 比对匹配情况
            c = strs[0][i]  # 取strs[0]当前第i个字符与其他字符串第i个字符对比
            for j in range(len(strs)):
                if i == len(strs[j]) or strs[j][i] != c:  # i == len(strs[j])为遍历完最小字串的情况， strs[j][i] != c为匹配不成功的情况，这两种情况都直接返回现有的匹配结果即可
                    return strs[0][: i]
        
        return strs[0]  # 默认返回第一个字符串
```


3. 分治算法
```
class Solution(object):
    def longestCommonPrefix(self, strs: str) -> str:
        if len(strs) == 0:  # 如果传入的list本身就是空的 直接返回空
            return ""
        
        return self.divide_rule(strs, 0, len(strs)-1)

    def divide_rule(self, strs, l, r):
        if l == r:
            return strs[l]
        else:
            mid = (l+r)//2  # 注意，这里整除要用//
            lcpLeft = self.divide_rule(strs, l, mid)
            lcpRight = self.divide_rule(strs, mid+1, r)
            return self.commonPrefix(lcpLeft, lcpRight)
    
    def commonPrefix(self, left, right):
        _min = min(len(left), len(right))
        for i in range(_min):
            if left[i] != right[i]:
                return left[: i]
        return left[: _min]
```

4. 二分查找
```
class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:  # 如果传入的list本身就是空的 直接返回空
            return ""

        minLen = min([len(s) for s in strs])
        low = 0
        high = minLen
        while low <= high:
            middle = (low + high) // 2
            if self.isCommonPrefix(strs, middle):  # 前面是有效的，继续找后面。
                low = middle + 1
            else:  # 前面是无效的，那后面的部分必定也无用缩小前区间的范围，继续往前寻找。
                high = middle - 1 

        return strs[0][: (low + high) // 2]
    
    def isCommonPrefix(self, strs, _len):
        tmp_str = strs[0][: _len]
        for i in range(len(strs)):  # 这里做的是垂直扫描
            if strs[i].find(tmp_str) != 0:
                return False
        return True
```

