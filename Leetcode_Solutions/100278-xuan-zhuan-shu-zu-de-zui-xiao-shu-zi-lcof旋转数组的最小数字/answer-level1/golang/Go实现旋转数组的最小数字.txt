
```golang
func minArray(numbers []int) int {
    l,r := 0,len(numbers)-1
    for numbers[l]>=numbers[r] && l<r{
        mid := l+(r-l)/2
        if numbers[mid]>numbers[l]{
            l=mid+1
        }else if numbers[mid]<numbers[l]{
            r = mid
        }else{
            l++
        }
    }
    return numbers[l]
}
```