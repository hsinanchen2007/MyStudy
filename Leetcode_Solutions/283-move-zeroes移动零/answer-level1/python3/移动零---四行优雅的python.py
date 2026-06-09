实现方式比较简单：
     1.遍历整个数组
     2.遇0删除
     3.在列表最后添加0
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        for i in nums[:]:
            if i==0:
                nums.append(0)
                nums.remove(0)
```


下面是改进后的写法
先数零的个数，再用append 和 remove暴力操作
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n = nums.count(0)
        for i in range(n):
            nums.append(0)
            nums.remove(0)


```
