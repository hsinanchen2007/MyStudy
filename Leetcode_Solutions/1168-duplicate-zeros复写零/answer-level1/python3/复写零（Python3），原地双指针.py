#### 思路
假设空间足够，得到的新数组长度为原数组长度加0的个数。定义两个指针分别指向原数组和新数组末尾，将原数组中的元素逐个移动到合适位置，最后把新数组多余部分去掉即可。
#### 代码
```
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        count_0 = arr.count(0)
        index_l = len(arr) - 1
        index_r = len(arr) - 1 + count_0
        arr.extend([None]*count_0) # 拓展数组长度
        while index_l < index_r:
            if arr[index_l] != 0:
                arr[index_r] = arr[index_l]
                index_l -= 1
                index_r -= 1
            else:
                arr[index_r] = arr[index_r-1] = 0
                index_l -= 1
                index_r -= 2
        for i in range(count_0):  # 还原数组长度
            arr.pop()
```
#### 复杂度分析
- 时间复杂度：O(N)，N为数组长度
- 空间复杂度：O(1),仅使用了`count_0`,`index_l`,`index_r`