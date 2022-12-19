# 方法一

![image.png](https://pic.leetcode-cn.com/5018fb33277800b6dbf22c2bdd2933c28797f1f77feece1dba945889549131df-image.png)
```
func missingNumber(nums []int) int {
    m := make([]byte, len(nums)+1)
    for _, v := range nums {
        m[v] = 1
    }
    for k, v := range m {
        if v != 1 {
            return k
        }
    }
    return -1    
}
```
# 方法二

![image.png](https://pic.leetcode-cn.com/6dd33dfab2a03e81e46dc91df7011901c1349429ce80f816aaec107736411e05-image.png)
```
func missingNumber(nums []int) int {
    n := len(nums)
    sum := 0
    for i:=0; i<n; i++ {
        sum += i-nums[i]
    }
    return sum+n
}
```
执行时间以实际为准.