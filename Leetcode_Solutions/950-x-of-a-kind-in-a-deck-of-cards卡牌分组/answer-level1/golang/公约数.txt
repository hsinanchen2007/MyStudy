### 解题思路

判断 数字出现的个数有没有大于1的公约数

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
    max := getMax(deck)
    res := make([]int, max+1)
    for _, cnt := range deck {
        res[cnt]++
    }
    g := -1
    for i := 0; i < max+1; i++{
        if res[i] > 0{
            if g == -1{
                g = res[i]
            } else {
                g = gcd(g, res[i])
            }
        }
    }
    return g >= 2
}

func getMax(nums []int) int {
    left, right := 0, len(nums)-1
    for left < right {
        if nums[left] < nums[right]{
            left++
        } else{
            right--
        }
    }
    return nums[left]
}

func gcd(a, b int) int{
    if a < b{
        a, b = b, a
    }
    for b != 0{
        a, b = b, a%b
    }
    return a
}
```