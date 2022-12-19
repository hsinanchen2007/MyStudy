### 解题思路
主要使用了动态规划的思想，考虑到对于当前数字而言，可能存在正负0三种情况，如果是负数，那么很显然，负负得正，前一步的最小值越小（负数），这一步可能获得的最大值就越大。
所以需要同时维护两个表格，分别是fmax,fmin，具体的实现比较简单

fmax从当前nums[i],nums[i]*fmax(i-1),num[i]*fmin(i-1) 三数取大，同样fmin从三数取小。

由于题目仅需要获取最大值，所以需要一个int型变量进行监听与记录。

初始赋值fmin  fmax  maxPro均为nums[0]。

### 代码

```golang
var fmax []int
var fmin []int
func maxProduct(nums []int) int {
    fmax=[]int{}
    fmin=[]int{}
    fmax=append(fmax,nums[0])
    fmin=append(fmin,nums[0])
    maxPro:=nums[0];
    if(len(nums)==1){
        return nums[0]
    }
    for i:=1;i<len(nums);i++{
        maxV:=int( math.Max(float64(nums[i]*fmax[i-1]),math.Max( float64(nums[i]*fmin[i-1]),float64(nums[i]))))
        minV:=int(math.Min(float64(nums[i]*fmax[i-1]),math.Min( float64(nums[i]*fmin[i-1]),float64(nums[i]))))
        if maxV>=maxPro{
            maxPro=maxV
        }
        fmax=append(fmax,maxV)
        fmin=append(fmin,minV)
    }
    return maxPro
}
```