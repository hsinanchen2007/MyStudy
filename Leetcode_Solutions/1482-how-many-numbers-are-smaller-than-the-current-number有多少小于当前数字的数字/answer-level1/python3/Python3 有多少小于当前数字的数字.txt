### 解题思路
这是我在leetcode上刷的第二道题，和第一道题一样，首先想到的还是这种最笨的方法。看了评论，发现用sort排序是非常省力的。

### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums) :
        list = []
        for i,num_1 in enumerate(nums):
            tem_num = 0
            for j,num_2 in enumerate(nums):
                if j == i:
                    continue
                elif num_2 < num_1:
                    tem_num += 1
            list.append(tem_num)
        return list
```