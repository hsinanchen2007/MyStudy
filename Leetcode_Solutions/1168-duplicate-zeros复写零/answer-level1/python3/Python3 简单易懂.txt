### 解题思路
遍历数组，当前值为**0**时，在为**0**的下一个位置插入一个**0**，下标**i**自增**1**，最后取修改后数组的前len(arrr)个数。
![WeChat Screenshot_20200114153408.png](https://pic.leetcode-cn.com/cc27e56a47bf27c1ac9ca1b4b254443cf7a5d390de18628d12f7441c2fe80030-WeChat%20Screenshot_20200114153408.png)



### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        arr_len = len(arr)
        i = 0
        while i < arr_len:
            if arr[i] == 0:
                arr.insert(i+1, 0)
                i +=1
            i +=1

        arr[:] = arr[:arr_len]
```