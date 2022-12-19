```
func distributeCandies(candies int, num_people int) []int {
    // 循环直到糖果分完，每次分的糖果计数num，(num-1) % num_people就是对应位置
    ret := make([]int, num_people)
    num := 0
    for candies > 0 {
        num++
        tmp := 0
        if candies >= num {
            tmp = num
        } else {
            tmp = candies
        }
        candies -= tmp
        ret[(num-1)%num_people] += tmp
    }
    return ret
}
```
