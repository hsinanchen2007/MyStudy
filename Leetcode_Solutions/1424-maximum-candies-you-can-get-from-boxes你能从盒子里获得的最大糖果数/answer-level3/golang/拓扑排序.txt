
按照题目的规则 搞个拓扑排序就可以了

```go
func maxCandies(status []int, candies []int, keys [][]int, containedBoxes [][]int, initialBoxes []int) int {
    queue := list.New()
    mmp := make(map[int]bool)
    for _, v := range initialBoxes {
        if status[v] == 1 {
            queue.PushBack(v)
        } else {
            mmp[v] = true
        }
    }
    
    sum := 0
    for queue.Len() > 0 {
        qf := queue.Front()
        u := qf.Value.(int)
        queue.Remove(qf)
        
        sum += candies[u]
        
        for _, v := range containedBoxes[u] {
            _, ok := mmp[v]
            if !ok {
                if status[v] == 1 {
                    queue.PushBack(v)
                    mmp[v] = false
                } else {
                    mmp[v] = true
                }
            }
            
        }
        
        for _, v := range keys[u] {
            status[v] = 1
            val, ok := mmp[v]
            if ok {
                if val {
                    queue.PushBack(v)
                    mmp[v] = false
                }
            }
        }
    }
    
    return sum
}
```
