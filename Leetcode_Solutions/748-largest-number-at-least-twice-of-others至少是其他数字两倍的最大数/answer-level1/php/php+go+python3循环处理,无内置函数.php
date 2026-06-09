1. 找出最大数
2. 遍历判断
```php []
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function dominantIndex($nums) {
        $idx = 0;
        for($i=0;$i<count($nums);$i++){
            $idx = ($nums[$idx]<<1) >= ($nums[$i]<<1) ? $idx : $i;
        }
        for ($i=0;$i<count($nums);$i++) {
            if ($i==$idx) {
                continue;
            }
            if ($nums[$idx] < ($nums[$i]<<1)) {
                return -1;
            }
        }
        return $idx;
    }
}
```
```go []
func dominantIndex(nums []int) int {
    idx := 0
    for k,_ := range nums {
        if (nums[idx]<<1) >= (nums[k]<<1) {
            idx = idx
        } else {
            idx = k
        }
    }
    for k,v := range nums {
        if k==idx {continue}
        if nums[idx] < (v<<1){return -1}
    }
    return idx
}
```
```python []
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        idx = 0
        for v in range(0,len(nums)):
            if nums[idx]<<1 >= nums[v]<<1 :
                idx = idx
            else: 
                idx = v
        
        for v in range(0,len(nums)):
            if v==idx:
                continue
            if nums[idx] < nums[v]<<1 :
                return -1
        
        return idx
```
