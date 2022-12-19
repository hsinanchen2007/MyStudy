### 解题思路
此处撰写解题思路

### 代码

```golang
func majorityElement(nums []int) int {
    m := make(map[int]int)
    for _, v := range nums {
        if _, ok := m[v]; ok {
            m[v] += 1
        } else {
            m[v] = 1
        }
        if m[v] > len(nums)/2 {
            return v
        }
    }
    return -1
}
```