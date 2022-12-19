### 解题思路
![WechatIMG12.png](https://pic.leetcode-cn.com/37f154e5d7dbf1086f418eb080fd45f40a869c172072c7c35219f14630f5180d-WechatIMG12.png)
因为a[i]的范围在1～n,所以可以用a的每项值作为新数组k的索引,出现k[j]就＋1,即K[i]等于2的元素，i即使所求元素

### 代码

```python3
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        a = [0]*(len(nums)+1)
        k = []
        for num in nums:
            a[num] += 1
        for j in range(1, len(a)):
            if a[j] == 2:
                k.append(j)
        return k
        
```