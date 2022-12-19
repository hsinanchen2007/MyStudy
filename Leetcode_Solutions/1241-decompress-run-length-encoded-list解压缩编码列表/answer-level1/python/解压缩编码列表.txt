### 解题思路
主要思想是利用列表推导，生成相应的数组。循环遍历数组中的偶数索引位置的值(0,2,4...).此值决定了生成数组的长度。然后将每个生成的数组拼接即可。
### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        i =0
        #避免作为循环条件时多次调用，浪费时间，故用以临时变量存取数组长度，当数组长度过大时，可以节约时间，避免重复多次调用len函数。
        l = len(nums)
        result = []
        while i < l:
            result +=[nums[i+1] for j in range(nums[i])]
            i +=2
        return result

```