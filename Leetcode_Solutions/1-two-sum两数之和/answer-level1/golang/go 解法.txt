
```
func twoSum(nums []int, target int) []int {
    for k1,v1 := range nums {
       for k2,v2 := range nums {
           if k1 != k2 { 
                if v1 + v2 == target {
                   return []int{k1,k2}
                }
            }
        }
    }
 return []int{}

}
```


两层遍历就可解决
加一个判断（避免同一个数相加）
比如：[]int{3,2,4} ，target = 6
不加判断的话会变成 3+3，会返回错误的0,0下标