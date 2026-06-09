### 解题思路
每个字母只有大写和小写两种 状态 可以对应到一个整数的二进制位上
比如 `a1b2` 有两个字母 所以可以映射为 两位二进制 也就是从0-3 如果一个整数对应位上的 bit为1 就映射为大写 反之映射为小写 比如 将整数3映射为`A1B2` 将整数2 映射为 `A1b2` 0 映射为`a1b2`
有n个字母 就对应为0-2^n-1范围内的整数 将这些整数迭代一遍并映射为对应的字符串即可

### 代码

```python
class Solution(object):
    
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        letterDict = {}
        for idx, c in enumerate(S):
            if c.isalpha():
                letterDict[idx] = c.lower()
        bitNum = len(letterDict)
        bit2Idx = list(letterDict.keys())
        strList = list(S)
        results = []
        for i in range(2 ** bitNum):
            for j in range(bitNum):
                strIdx = bit2Idx[j]
                if (1 << j) & i != 0:
                    strList[strIdx] = strList[strIdx].lower()
                else:
                    strList[strIdx] = strList[strIdx].upper()
            results.append("".join(strList))
        return results
    

```