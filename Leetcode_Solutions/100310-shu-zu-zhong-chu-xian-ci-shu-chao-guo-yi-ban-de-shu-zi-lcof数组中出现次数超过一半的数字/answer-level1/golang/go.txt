```golang
func majorityElement(nums []int) int {
    val, cnt := 0, -1
    for _, e := range nums {
        if cnt <= 0 {
            val = e
            cnt = 1
        } else if val == e{
            cnt ++
        } else {
            cnt --
        }
    }
    return val
}
```