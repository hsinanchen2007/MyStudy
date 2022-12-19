```
func longestMountain(_ A: [Int]) -> Int {
        var right = 0
        var length = 0
        var arr = [Int]()
        var up = false
        var down = false
        while right < A.count - 1 {
            if A[right] < A[right + 1] {
                if (down && !up) && (length > 0) {
                    arr.append(length)
                    length = 0
                }
                length += 1
                up = true
                down = false
            }
            if A[right] > A[right + 1] {
                if (up && !down) || (!up && down) {
                    length += 1
                    up = false
                    down = true
                }
                if (right == A.count - 2) && (length > 0) {
                    arr.append(length)
                    length = 0
                }
            }
            if A[right] == A[right + 1] {
                if down && !up {
                    arr.append(length)
                }
                length = 0
                up = false
                down = false
            }
            right += 1
        }
        var max = 0
        for num in arr {
            if num > max {
                max = num
            }
        }
        return max > 0 ? max + 1 : 0
    }
```


