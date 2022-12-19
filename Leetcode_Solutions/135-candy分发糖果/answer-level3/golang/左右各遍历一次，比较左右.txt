### 解题思路
左右各遍历一次，比较左右

### 代码

```golang
func candy(ratings []int) int {
    l := len(ratings) 
    if l == 0 {
        return 0
    }
    if l == 1 {
        return 1
    }
    var res []int
    res = append(res, 1)
    for i := 1; i < l; i++ {
        if ratings[i] > ratings[i - 1] {
            res = append(res, res[i - 1] + 1)
        } else {
            res = append(res, 1)
        }
    }
    var sum = res[l - 1]
    for i := l - 2; i >= 0; i-- {
        if ratings[i] > ratings[i + 1] && res[i] <= res[i + 1] {
            res[i] = res[i + 1] + 1
        }
        sum = sum + res[i]
    }
    return sum
}
```