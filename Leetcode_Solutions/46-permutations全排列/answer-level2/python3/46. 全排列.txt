### 解题思路
回溯法求全排列
第一步，把序列看做两个部分，第一部分是第一个元素，第二部分是第一个元素之后的所有元素
第二步，将第一个元素和后面的每个元素交换位置，然后递归求后面子序列的全排列
第三步，每次求完子序列的全排列之后将第一个元素回复到原来的位置
结束条件：当子序列里只剩下一个元素的时候，整个序列就是一个排列
### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def permution(arr, position, end):
            if position == end - 1:
                res.append(arr.copy())

            for i in range(position, end):
                arr[position], arr[i] = arr[i], arr[position]
                permution(arr, position + 1, end)
                arr[i], arr[position] = arr[position], arr[i]

        permution(nums, 0, len(nums))
        res = sorted(res)

        return res
```