### 解题思路
此处撰写解题思路

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
    var (
        result []int
        helper func(arr []int,k int)
    )
    helper = func(arr []int,k int){
        if len(arr) == 0 {
            return 
        }
        if len(arr) == k {
            result = append(result,arr...)
            return
        }
        var (
            left = 1
            right = len(arr)-1
            cur = arr[0]
        )
        for {
            for right >= 1 && arr[right] >= cur {
                right --
            }
            if left < len(arr) && arr[left] < cur {
                left ++
            }
            if left >= right {
                break
            }
            arr[left],arr[right] = arr[right],arr[left]
        }
        arr[0],arr[right] = arr[right],arr[0]
        if right+1 == k {
            result = append(result,arr[:right+1]...)
            return
        }
        if right+1 < k {
            result = append(result,arr[:right+1]...)
            helper(arr[right+1:],k-right-1)
            return
        }
        helper(arr[:right],k)
    }
    helper(arr,k)
    return result
}
```