```
func duplicateZeros(arr []int) {
    var start, length int
    var ignoreLastZero bool
    for start = 0; start < len(arr); start++ {
        length++
        if arr[start] == 0 {
            if length == len(arr) {
                ignoreLastZero = true
                break
            }
            length++
        }
        if length == len(arr) {
            break
        }
    }
    if start == len(arr) {
        start--
    }

    j := len(arr) - 1
    for i := start; i >= 0; i-- {
        arr[j] = arr[i]
        j--

        if arr[i] == 0 {
            if ignoreLastZero {
                ignoreLastZero = false
                continue
            }
            arr[j] = arr[i]
            j--
        }
    }
}
```
