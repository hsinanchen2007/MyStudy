
从后往前推

i 表示符合要求的位置（从末尾开始）。
j是它前一位，从它开始向前寻找能跳到i 的位置，找到即值赋给 i(可能直到0位置都找不到，返回False)。
最终跑完如果 i 等于起点0位置，返回True（说明起点可以到终点）

```
def canJump(self, nums: List[int]) -> bool:
        i=len(nums)-1
        while i>0:
            j=i-1
            while nums[j]+j<i:
                j-=1
                if j==-1:
                    return False
            i=j
        return i==0 
```

