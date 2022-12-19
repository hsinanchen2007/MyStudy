```
func lengthOfLongestSubstring(s string) int {
    //滑动窗口sliding window (low -- high)
    //high的作用是使这个窗口更大，所以始终向后移动
    //low的作用是确保这个窗口是有效的，此处为不能含有重复字符, 引入set
    if len(s) == 0  {
        return 0
    }
    str := []byte(s)

    low, high := 0, 0
    maxLength := 1

    data := make(map[byte]bool, 0)
    for ;high < len(str); high++ {
        cur := str[high]
        if _, ok := data[cur]; ok {
            for low < high && str[low] != cur {
                delete(data, str[low])
                low++
            }
            low++
        } else {
            data[cur] = true
        }
        maxLength = int(math.Max(float64(maxLength),float64(high-low+1)))
    }
    return maxLength
}
```
