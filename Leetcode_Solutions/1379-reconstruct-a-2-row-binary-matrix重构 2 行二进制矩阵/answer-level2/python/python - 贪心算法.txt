**1. 解题思路**

- 贪心算法  
    1. 遍历colsum的长度
    2. 当值为2时，upper和lower都应该是1
    3. 当值为0时，upper和lower都应该是0
    4. 当值为1时，需要对比剩下的upper和lower的总和, 较大的应该是1，较小的是0(这样才能避免在后面出现2时，无法放值) 
    5. 判断剩下的upper的总和和lower的总和， 都为0时， 则证明有解

**2. 代码**

```
class Solution(object):
    def reconstructMatrix(self, upper, lower, colsum):
        """
        :type upper: int
        :type lower: int
        :type colsum: List[int]
        :rtype: List[List[int]]
        """
        if upper + lower != sum(colsum):
            return []

        rows = len(colsum)
        ans = [[], []]

        remain_upper, remain_lower = upper, lower
        for i in range(rows):
            ans_upper = ans_lower = 0
            if colsum[i] == 2:
                ans_upper = ans_lower = 1

            elif colsum[i] == 1:
                if remain_upper > remain_lower:
                    ans_upper = 1
                else:
                    ans_lower = 1

            remain_upper -= ans_upper
            remain_lower -= ans_lower
            ans[0].append(ans_upper)
            ans[1].append(ans_lower)

        if remain_upper or remain_lower:
            return []

        return ans
```
