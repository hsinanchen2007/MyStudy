#### 思路
1. 升序排列数组存入目标数组`targ`；
2. 将原始数组`nums`和目标数组`targ`比对；
3. 将首尾相同的元素删掉，直到有不同；
4. 记住首尾不同元素的位置，切片即可。
#### 代码
```python
def findUnsortedSubarray(nums):
    targ=sorted(nums)
    if targ==nums:
        return 0
    i,j=0,len(nums)-1
    while nums[i]==targ[i]:
        i=i+1
    while nums[j]==targ[j]:
        j=j-1
    return len(nums[i:j+1])
```

#### 结果
![QQ.png](https://pic.leetcode-cn.com/125caf07fb7d39ee670191fcd66f58f8679feed880ce9ee62170378c00d22e22-QQ.png)
200多ms竟然还能击败98.51%的用户......