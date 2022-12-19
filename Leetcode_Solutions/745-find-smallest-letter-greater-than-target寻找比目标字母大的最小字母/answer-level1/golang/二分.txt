因为循环，首先判断最后一个数字和target 比较
```
func nextGreatestLetter(letters []byte, target byte) byte {
    if target >= letters[len(letters)-1] || target < letters[0]{
        return letters[0]
    }
    left := 0
    right := len(letters)-1
    for left <= right {
        mid := left + (right-left)/2
        if letters[mid] <= target {
            left = mid+1
        }else {
            right = mid-1
        }
    }
    return letters[left]
}

```
