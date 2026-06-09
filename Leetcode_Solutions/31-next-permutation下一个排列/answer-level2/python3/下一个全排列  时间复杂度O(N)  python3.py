### 解题思路
![下一个排列.jpg](https://pic.leetcode-cn.com/c2357f5038f74d56a9ef173d1000dd68d6b18f5c4f6c792e2f641b024883cf14-%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%8E%92%E5%88%97.jpg)

1. 首先，逆序遍历列表，寻找到元素值比前一个元素值小的位置。如图，单独用红色标记出来的5，就是我们要寻找的位置
2. 然后在红色标记的右边，寻找到大于红色标记值的数字中最小的那个数字，所对应的索引，作为switch_index保存下来
3. 然后将红色标记和switch_index处的值互换
4. 然后将列表中红色标记之后的部分排序，或者是翻转

另外，要做一个是否找到switch_index的判断，如果没有找到switch_index，那么说明该列表从后往前递减的，按照题意直接翻转列表即可。
![下一个全排列.png](https://pic.leetcode-cn.com/abc35fd51083d63d4c83a61f972733b5d0eda29de97138c643dccf21f6366ec6-%E4%B8%8B%E4%B8%80%E4%B8%AA%E5%85%A8%E6%8E%92%E5%88%97.png)


### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        switch = False
        for i in range(len(nums)-1, 0, -1):
            if nums[i]-nums[i-1] > 0:
                min_bigger_num = float("inf")
                for j in range(i, len(nums)):
                    if nums[j] > nums[i-1] and nums[j] <= min_bigger_num:
                        min_bigger_num = nums[j]
                        switch_index = j
                nums[switch_index], nums[i-1] = nums[i-1], nums[switch_index]
                switch = True
                break
        if not switch:
            i=0 
        n = 0
        for j in range(i, len(nums)):
            n+=1
            if len(nums)-n > j:
                nums[j], nums[len(nums)-n] = nums[len(nums)-n], nums[j]

```