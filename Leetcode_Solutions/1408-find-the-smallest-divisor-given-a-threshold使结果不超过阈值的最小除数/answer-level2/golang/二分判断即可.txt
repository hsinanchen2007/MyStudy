题解 大佬们都写了,  我来分享想`Go`的代码


```go
func smallestDivisor(nums []int, threshold int) int {
    var l = 1
    var r = 5000000
    var mid int
    var ans int = 0
    for sum:=0; l <= r; {
        mid = (l+r)/2
        sum = 0
        for _, v := range nums {
            sum += (v+mid-1)/mid
        }
        fmt.Println(mid, sum)
        if sum > threshold {
            l = mid+1
        } else {
            r = mid-1
            ans = mid
        }
    }
    return ans
}
```