
![image.png](https://pic.leetcode-cn.com/cb8bd3bcf2cac7c60020170704ce6d24ea580647ff39a47a450c4109918dcee6-image.png)

累加 0~n 本应该的和，然后再累加数组 nums 的和，因为只缺失一个数，所以两个和相减便是缺失的数。

代码
```
func missingNumber(nums []int) int {    // 求和相减即可求出缺失的数
    length := len(nums)
    sum1,sum2 := length,0
    for i:=0; i<length; i++ {
        sum1 += i
        sum2 += nums[i]
    }
    return sum1-sum2
}
```