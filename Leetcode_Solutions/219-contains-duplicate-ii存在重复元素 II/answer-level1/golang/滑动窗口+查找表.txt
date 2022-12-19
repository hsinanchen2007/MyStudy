### 解题思路
此处撰写解题思路

### 代码

```golang
func containsNearbyDuplicate(nums []int, k int) bool {
    var record = make(map[int]int)

    for i:=0; i<len(nums); i++ {
        if _, ok := record[nums[i]]; ok {
            return true
        }
        record[nums[i]] = 1
        if len(record) == k+1 {
            delete(record, nums[i-k])
        }
    }

    return false
}
```