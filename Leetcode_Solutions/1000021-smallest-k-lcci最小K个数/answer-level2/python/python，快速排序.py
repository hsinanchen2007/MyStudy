### 解题思路
因为只要返回前k个小数，而无需这k个数间的顺序，所以应用快速排序的思想，对原数组的给定区间进行分块，当分块的点
刚好等于k时，直接返回，否则对相应的子块进行递归分块。

### 执行结果
![image.png](https://pic.leetcode-cn.com/87e2c81f7280e2e6ed41c8ef2cdaf23dc1d45c2bea156d76b2ecfebc74ecfe2e-image.png)

### 代码

```python3
class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:
        def helper(arr, k, left, right):
            ##### 标准快速排序
            pivot = left
            low, high = left, left+1
            for high in range(left+1, right+1):
                if arr[high] < arr[pivot]:
                    low += 1
                    arr[low], arr[high] = arr[high], arr[low]
            arr[left], arr[low] = arr[low], arr[left]
            ###若当前分块长度不等于目标长度k，则根据情况进行下一步细分
            if low-left+1 < k:
                helper(arr, k-low+left-1, low+1, right)
            elif low-left+1 > k:
                helper(arr, k, left, low-1)
        
        if not arr or not k:
            return []
        helper(arr, k, 0, len(arr)-1)
        return arr[:k]

```