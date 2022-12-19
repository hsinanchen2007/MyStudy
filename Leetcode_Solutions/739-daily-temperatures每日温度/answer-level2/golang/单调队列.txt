```
func dailyTemperatures(T []int) []int {
    //单调递减队列
    l := len(T)
    queue, ans := make([]int, l),make([]int, l)
    for i := 0; i < l; i++ {
        //队列中元素小于当前元素
        for len(queue) != 0 && T[queue[len(queue) - 1]] < T[i] {
            tail := queue[len(queue) - 1]
            queue = queue[:len(queue) - 1]
            ans[tail] = i - tail 
        }
        queue = append(queue, i)
    }   
    return ans
}
```
