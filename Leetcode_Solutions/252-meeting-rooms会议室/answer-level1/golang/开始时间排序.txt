![image.png](https://pic.leetcode-cn.com/a84b72b8fcfcb5c5e1744db800dd508a23a1dfdae3b48d9f7c2d3c2b6a12e845-image.png)
如果开始时间相同,return false
如果开始时间小于前一段结束时间,return false

```
func canAttendMeetings(intervals [][]int) bool {
    //按会议开始时间排序
    m  := make(map[int]int)
    for _, v := range intervals {
        _, ok := m[v[0]]
        if ok {
            return false
        }else {
            m[v[0]] = v[1]
        }
    }
    var keys []int
    for k := range m {
        keys = append(keys,k)
    }
    sort.Ints(keys)
    pre := 0
    for i := range keys {
        if keys[i] < pre {
            return false
        }
        pre = m[keys[i]]
    }
    return true
}
```