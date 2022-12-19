
- **执行结果：**
![0.png](https://pic.leetcode-cn.com/891a68a5e4c8ff88c89c2f01c3146f67512d7489f34689d9416cf7e28b75bb8e-0.png)

- **循环一遍，每一步都找出能跳最远的点**
```
func jump(nums []int) int {
    lens := len(nums)
    if lens <= 1 {
        return 0
    }
    res := 0
    i := 0
    for ;i<lens; {
        if i + nums[i] >= lens - 1 {
            res++
            return res
        }
        
        itemIndex := i
        item := 0
        //当前值+下一个值计算最大和
        for n:=1; n<=nums[i] && i+n<lens; n++{
            if n + nums[i+n] >= item {
                item = n + nums[i+n]
                itemIndex = i+n
            }
        }
        
        i = itemIndex
        res++
    }
    
    return res
}
```
