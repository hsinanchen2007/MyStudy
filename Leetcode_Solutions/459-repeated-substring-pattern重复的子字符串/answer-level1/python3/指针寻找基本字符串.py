```
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:

        
        pIdx = max(s.index(i) for i in set(s))
        while pIdx <= len(s) / 2 - 1:
            basicStr = s[:pIdx+1]
            if not any(s.split(basicStr)):
                return True
            pIdx += 1
        return False
```

可以肯定的规则有以下两条:
* 基本字符串p一定是从s开头的字符串
* p在s中至少重复一次即pp


考虑复杂一点的情况，基本字符串应该包含多个字母，在这些字母中，我们以最远的那个字母的索引作为匹配指针的开始，直到整个字符串一半的结尾停止。

值得注意的是，这里while循环满足的条件实际上一语双关了
1. 第一层意思：

假定`s= 'abaaabaa'`，则匹配指针应该从索引1处开始，到索引3处结束

2. 第二层意思：

假定`s = 'ababc'`，此时的匹配指针从c开始了，不满足匹配指针的边界条件，故直接返回`Fasle`



