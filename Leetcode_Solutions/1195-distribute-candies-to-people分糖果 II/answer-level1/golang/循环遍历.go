### 解题思路
此处撰写解题思路
循环遍历，没有算法

### 代码

```golang
func distributeCandies(candies int, num_people int) []int {
    sum := 0
    n := 1
    i := 0
    ans := make([]int, num_people)
    for sum < candies {
        ans[i] += n
        i++
        i = i % num_people
        sum += n
        if candies-sum > n {
            n++
        } else {
            n = candies - sum
        }
    }
    return ans
}

```