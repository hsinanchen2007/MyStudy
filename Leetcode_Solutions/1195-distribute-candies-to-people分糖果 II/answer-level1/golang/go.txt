### 解题思路
此处撰写解题思路

### 代码

```golang
func distributeCandies(candies int, num_people int) []int {
    res := make([]int,num_people)
    cur := 1
    i := 0
    for candies > 0{
        if cur > candies{
            res[i] += candies
        }else{
            res[i] += cur
        }
        candies -= cur
        cur += 1
        i += 1
        if i == num_people{
            i = 0
        }
    }
    return res
}
```