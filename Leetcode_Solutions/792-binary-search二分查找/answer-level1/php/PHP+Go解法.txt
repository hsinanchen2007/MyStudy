标准的无重复字符数组的二分查找
```php []
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        if (empty($nums)) {
            return -1;
        }
        $l = 0;
        $r = count($nums) - 1;
        while($l<=$r){
            $mid = $l + (($r - $l) >> 1);
            if ($nums[$mid] == $target){
                return $mid;
            } elseif ($nums[$mid] > $target) {
                $r = $mid - 1;
            } else {
                $l = $mid + 1;
            }
        }
        return -1;
    }
}
```
```go []
func search(nums []int, target int) int {
  if len(nums) == 0 {return -1}
  count := len(nums)
  l,r := 0, count - 1
  for l<=r {
    mid := l + ((r-l) >> 2)
    if nums[mid] == target {
      return mid
    } else if nums[mid] > target{
      r = mid - 1
    } else {
      l = mid + 1
    }
  }
  return -1
}
```