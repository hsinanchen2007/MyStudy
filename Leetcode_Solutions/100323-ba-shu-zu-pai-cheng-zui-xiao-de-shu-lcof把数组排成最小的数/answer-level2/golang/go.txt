```golang
func minNumber(nums []int) string {
    sort.Slice(nums, func(i, j int) bool {
        return strconv.Itoa(nums[i]) + strconv.Itoa(nums[j]) < strconv.Itoa(nums[j]) +strconv.Itoa(nums[j]);
    })
    var ans string 
    for _, v := range nums {
        ans += strconv.Itoa(v)
    }
    str := []byte(ans)
    k := 0
    for (str[k] == 0) {
        k++
    }
    str = str[k:]
    return string(str)
}
```