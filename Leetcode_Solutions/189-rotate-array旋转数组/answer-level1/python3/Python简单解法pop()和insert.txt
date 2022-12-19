### 解题思路
1、先把最后一个数pop出来，
2、然后再将数字insert在头位置即可
3、pop是O(1),insert是O(n),还有一个循环，所以时间复杂度有点高


### 代码
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(k):
            a = nums.pop()
            nums.insert(0,a)
```
