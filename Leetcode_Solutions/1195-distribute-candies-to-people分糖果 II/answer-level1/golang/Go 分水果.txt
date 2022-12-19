### 解题思路
此处撰写解题思路
1. 设置一个全局变量 记录给上一次糖果的分配数结果 总数一并剪去share
2. 设置一个for循环 里面的基本操作就是对人进行分配糖果
### 代码

```golang
func distributeCandies(candies int, num_people int) []int {
    share := 1
    res := make([]int, num_people)
    for candies > 0 {
        for i := 0; i < num_people && candies > 0; i++ {
            if share <= candies {
                  res[i] += share
            } else {
                 res[i] += candies
            }

            candies = candies - share
            share++
        }
    }
    return res
}
```