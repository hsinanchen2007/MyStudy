### 解题思路
1、for循环
2、把后面k个值赋值到新数组的前k个
3、再把剩下的接着赋值到新数组里

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        new = [0]*length
        for i in range(length):
            #把后面k个值赋值到新数组的前k个
            if i < k:
                new[i] = nums[length-k+i]
            #再把剩下的接着赋值到新数组里
            else:
                new[i] = nums[i-k]
        print(new)
        #注意赋值方式
        nums[:]=new[:]
        #如果赋值写为nums=new方法打印出来已旋转，但输出却没有变，说明原地方的内存未变
        print(nums)


       
```