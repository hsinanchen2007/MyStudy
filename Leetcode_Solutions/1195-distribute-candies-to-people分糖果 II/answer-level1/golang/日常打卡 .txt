### 解题思路
暴力模拟
### 代码

```golang
func distributeCandies(candies int, num_people int) []int {
    ans := make([]int,num_people)
    i := 0 
    for candies > 0 {
        ans[i % num_people] += Min(candies, i + 1)
        i += 1
        candies -= i
    }
    return  ans
}

func Min(a,b int) int {
    if a < b {
        return a
    }
    return b
}
```