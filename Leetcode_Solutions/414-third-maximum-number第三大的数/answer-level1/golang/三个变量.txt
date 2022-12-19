![image.png](https://pic.leetcode-cn.com/f1a52c60f9211233dbc7e795bcf824ca7a6e8643b82b090da000da5bd370aa94-image.png)


```
func thirdMax(nums []int) int {
    if len(nums) <= 0 {
        return 0
    }
    
    var a = ^(int(^uint(0) >> 1))
    var b = ^(int(^uint(0) >> 1))
    var c = ^(int(^uint(0) >> 1))
    var m = make(map[int]int)
    for i:=0; i<=len(nums)-1; i++{
        if nums[i] > a{
            c = b
            b = a
            a = nums[i]
        }else if nums[i] < a && nums[i] > b {
            c = b
            b = nums[i]
        }else if nums[i] < a && nums[i] < b && nums[i] > c{
            c = nums[i]
        }
        m[nums[i]] = 1
    }
    // fmt.Println(a)
    // fmt.Println(c)
    // fmt.Println(m)
    if len(m) >= 3{
        return c
    }else{
        return a
    }
    
}
```
