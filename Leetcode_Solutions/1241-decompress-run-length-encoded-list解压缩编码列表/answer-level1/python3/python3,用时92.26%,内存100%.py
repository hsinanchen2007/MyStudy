### 解题思路
遍历一遍list即可：对于列表中的数字，偶数位置是内容，前一个位置（奇数位置）是次数，找到偶数位置的内容，并append相应次数即可。

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        count = 0
        lis = []
        for i in nums:
            count += 1
            if count % 2 == 0:
                while(nums[count-2]):
                    lis.append(i)
                    nums[count-2] -=1
        return lis

```