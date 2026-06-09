```

func hIndex(citations []int) int {
    if len(citations) == 0 {
        return 0
    } 
    qSort(citations, 0, len(citations)-1)

    if citations[len(citations)-1] == 0 {
        return 0
    }
    if len(citations) == 1 && citations[0] >= 1 {
        return 1
    }

    h := 0

    for i, _ := range citations {
        if citations[i] >= len(citations)-i {
            if len(citations) - i > h {
                h = len(citations) - i
            }
        }
    }
    return h
}

func qSort(array []int, left, right int) {
    if left < right && left >= 0 {
        l, r := left, right 
        middle := array[(l+r)>>1]
        for l < r {
            for l < r && array[l] < middle {
                l++
            }
            for l < r && array[r] > middle {
                r--
            }
            if l >= r {
                break
            }
            if array[l] == array[r] && array[r] == middle {
                r--
            } else {
                array[l], array[r] = array[r], array[l]
            }
        }
        qSort(array, left, l-1)
        qSort(array, r+1, right)
    }
}

```
