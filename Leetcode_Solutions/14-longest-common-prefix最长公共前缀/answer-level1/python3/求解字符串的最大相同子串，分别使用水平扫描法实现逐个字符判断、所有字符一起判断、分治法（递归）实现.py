### 解题思路
1. 水平扫描法，逐个字符串进行判断，寻找最大子串，时间复杂度O(s)，空间复杂度O(1)。
2. 水平扫描法，所有字符同时比较，时间复杂度为O(s)，空间复杂度为O(1)。
3. # 分治法，运用递归进行分治，每次将子串换分为两端进行判断。时间复杂度O(s)，空间复杂度O(mlogn)
### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # 水平扫描法，逐个字符串进行判断，寻找最大子串，时间复杂度O(s)，空间复杂度O(1)。
        """
        if len(strs) == 0:
            return ''
        prefix = strs[0]
        for i in range(1, len(strs)):
            while strs[i].find(prefix) != 0:
                prefix = prefix[0:len(prefix)-1]
                if len(prefix)==0:
                    return ''
        return prefix
        """

        # 水平扫描法，所有字符同时比较，时间复杂度为O(s)，空间复杂度为O(1)。
        """
        if len(strs) == 0:
            return ''
        profix = ''
        for i in range(len(strs[0])):
            string = strs[0]
            for j in range(1, len(strs)):
                if i >= len(strs[j]) or string[i] != strs[j][i]:
                    return profix
            profix = profix + string[i]
        return profix
        """

        # 分治法，运用递归进行分治，每次将子串换分为两端进行判断。时间复杂度O(s)，空间复杂度O(mlogn)
        if len(strs) == 0:
            return ''
        return self.stringDivide(strs, 0, len(strs)-1)
    
    def stringDivide(self, string, left, right):
        if left == right:
            return string[left]
        else:
            mid = int((left+right)/2)
            lcpLeft = self.stringDivide(string, left, mid)
            lcpRight = self.stringDivide(string, mid+1, right)
            return self.lcpMax(lcpLeft, lcpRight)
    
    def lcpMax(self, lcpLeft, lcpRight):
        minLen = min(len(lcpLeft), len(lcpRight))
        for i in range(minLen):
            if lcpLeft[i] != lcpRight[i]:
                return lcpRight[0:i]
        return lcpRight[0:minLen]
```