```
func depthSum(nestedList []*NestedInteger) int {
    var ans int
    var queue []*NestedInteger

    depth := 1
    for _, ele := range nestedList {
        queue = append(queue, ele)
    }

    for len(queue) > 0 {
        size := len(queue)
        for i := 0; i < size; i++ {
            ele := queue[i]
            if ele.IsInteger() {
                ans += depth * ele.GetInteger()
                continue
            }

            for _, ele2 := range ele.GetList() {
                queue = append(queue, ele2)
            }
        }

        queue = queue[size:]
        depth++
    }

    return ans
}
```
