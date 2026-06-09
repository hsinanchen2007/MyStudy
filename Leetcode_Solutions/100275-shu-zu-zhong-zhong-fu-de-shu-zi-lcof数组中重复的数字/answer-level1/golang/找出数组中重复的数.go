### 解题思路
俩种方法：

### 代码

第一种使用数组做标记
```
func findRepeatNumber(nums []int) int{

    max := mAX(nums)
    indexSlice := make([]int, max+1)

    length := len(nums)
    for i:=0; i<length; i++ {
        if indexSlice[nums[i]] == 0 {
            indexSlice[nums[i]]++
        }else{
            return nums[i]
        }
    }
    return -1
}

func mAX(arr []int) int {
    max := 0
    for i:=0;i<len(arr);i++ {
        if arr[i] > max {
            max = arr[i]
        }
    }
    return max
}
```

第二种方法用set
```
func findRepeatNumber(nums []int) int {
    
    map1 := make(map[int]int)
    for i:=0; i<len(nums); i++ {
        if _, ok := map1[nums[i]]; ok {
            return nums[i]
        }else{
            map1[nums[i]] = 0
        }
    }
    return -1
}
```
