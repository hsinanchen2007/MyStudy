### 解题思路
此处撰写解题思路

### 代码

```golang
func hIndex(citations []int) int {
    sort.Ints(citations)
    length := len(citations)
  
    for i := range citations {
        if citations[i] >=  length- i{
            return length- i
        }
    }
    return 0
}
```