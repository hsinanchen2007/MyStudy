```go []
func findMagicIndex(nums []int) int {
    for key,value:=range nums{
        if value==key{
            return value
        }
    }
    return -1
}
```

