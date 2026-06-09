```
func nextGreatestLetter(letters []byte, target byte) byte {
    var i, j, mid ,res int
    i = 0
    j = len(letters)-1
    for i<=j{
        mid = (i+j)/2
    if letters[mid] <= target{
            i = mid + 1
        }else{
            j = mid -1
        }

    }
    if i > mid {
        res = i
    }else if j < mid{
        res = mid
    }else{
        res = mid+1
    }
    return letters[res % len(letters)]
}
```