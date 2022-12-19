### 解题思路
本题应该应该记录一个最大值imax，一个最小值imin，因为最大值乘以负数就变成了最小值，最小值乘以负数会变成最大值。因为有0值存在，找最大值时当然要跳过0值，所以使用:max(nums[i],imax*nums[i]).此句保证遇到0时从后面开始重新记录正值。

### 代码

```golang
func maxProduct(nums []int) int {
    if len(nums)<=0{
        return 0
    }
    if len(nums)==1{
        return nums[0]
    }
    imin:=1
    imax:=1
    mx:=^(int(^uint(0)>>1))

    for i:=0;i<len(nums);i++{
        tmp:=imax
        imax=max(max(nums[i],imax*nums[i]),imin*nums[i])
        imin=min(min(nums[i],imin*nums[i]),tmp*nums[i])

        mx=max(mx,imax)
    }

    return mx
}

func max(a,b int) int{
    if a>b{
        return a
    }

    return b
}
func min(a,b int) int{
    if a<b{
        return a
    }

    return b
}
```