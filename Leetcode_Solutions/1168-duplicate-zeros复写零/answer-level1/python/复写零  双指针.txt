### 解题思路
需要注意最后一个有效0能否被复写
### 代码

```python
class Solution(object):
    def duplicateZeros(self, arr):
        left,right = 0,len(arr)-1
        while left <= right:
            if arr[left] == 0:
                arr[right] = 0
                right -= 1
            left += 1       #首先确定要去掉的部分，将这部分元素均变为0
        j = len(arr) - 1
        count = 0
        for i in range(left-1,-1,-1):  #从未被去除的最后一个元素倒序变换元素位置，变换位置从arr[-1]开始
            if arr[i] != 0:            #因为上一步操作中已经将去掉部分赋值为0，所以遇到0就可以直接改变j的值
                if i != j:
                    arr[j] = arr[i]
                    arr[i] = 0
                j -= 1
            else:
                if i == left - 1 and left - right == 2:
                    j -= 1
                else: 
                    j -= 2
                count += 1   #共走过了几个需要复写的0
                if count == len(arr) - 1 - right:
                    break
        return 
```