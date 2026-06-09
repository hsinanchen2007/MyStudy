### 解题思路
采用滑动窗口的思路
### 代码

```golang
func containsNearbyDuplicate(nums []int, k int) bool {
    var l,r int 
    if k == 0 {
        return false
    }

    for r < len(nums){
        if nums[l] == nums[r] && r != l{
            return true
        }
        if r - l >= k{
            l++
            continue
        } 
        r++
    }
    r--
	for l < r  {
		if nums[l] == nums[r]{
			return true
		}
		l++
	}
    return false
}
```