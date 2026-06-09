memo为set，记录近k个出现的元素。i为滑动指针，p为左指针，只有两种情况左指针前移动。
1. 当第i位元素是否在memo中出现，如果出现，左指针前移，并删除S[p]元素直到S[i]在memo中未出现
2. 当i-p+1，即子字符串长度等于K时，记录答案后，左指针前移一位。

```
class Solution(object):
    def numKLenSubstrNoRepeats(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: int
        """
        if not S or K == 0: return 0
        memo = set()
        l = 0
        ans = 0
        for i in range(len(S)):
            
            while S[i] in memo:
                memo.remove(S[l])
                l += 1
            memo.add(S[i])

            if i-l+1 == K:
                ans += 1
                memo.remove(S[l])
                l+=1

        return ans
```



