题干：要求相邻得分最高者得糖果最多，且每人至少一个糖果

思路：  
题干包含三层意思：
1. 每人至少一颗糖
2. 如果得分nums[i]>nums[i-1]，则奖励reward[i]要大于reward[i-1]
3. 如果nums[i]>nums[i+1]，则reward[i]要大于reward[i+1]

所以可以分三步处理：
1. 第一轮循环，初始化reward每个人分一颗糖
2. 第二轮循环，比较i与其左i-1，当nums[i]>nums[i-1]，则给i的糖要比i-1的多，按题意给最少即+1，又因为现在任意i，有reward[i] = 1,所以：reward[i] = reward[i-1]+1
3. 第三轮循环，比较i与其右i+1，当nums[i]>nums[i+1]，则给i的糖要比i-1的多，因为有些i已经得到了更多的糖，所以要比较reward[i]与reward[i+1]+1的关系，小于时要reward[i]=reward[i+1]+1

最后因为初始化赋值时的操作可以和与左比较一起，所以只需要两轮循环即可，代码如下：
```go
func candy(nums []int) int {
    if nums == nil || len(nums) == 0 {
        return 0
    }
    
    n := len(nums)
    reward := make([]int,n)

    // 初始化每个人所分糖果，并比较左值
    reward[0] = 1
    res := 1
    for i:=1;i<n;i++{
        if nums[i]>nums[i-1]{
            reward[i] = reward[i-1]+1
        }else{
           reward[i] = 1 
        }
        res += reward[i]
    }
    
    // 比较右值，使得分最高者糖果最多
    for i:=n-2;i>=0;i--{
        diff := reward[i+1]+1-reward[i]
        if nums[i]>nums[i+1] && diff> 0{
            reward[i] += diff
            res += diff
        }
    }
    

    return res
}
```