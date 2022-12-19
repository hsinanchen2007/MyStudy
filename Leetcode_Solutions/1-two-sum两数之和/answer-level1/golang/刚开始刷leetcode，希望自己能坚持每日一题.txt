### 解题思路
这道题我使用了冒泡排序的思路，效率可能不高，但是解法应该是对的。

### go代码

```golang
func twoSum(nums []int, target int) []int {
    result := make([]int, 2)
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            if nums[i] + nums[j] == target {
                result = []int{i, j}
            }
        }
    }
    return result
}
```
### php代码
```php
function twoSum($nums, $target) {
    $result = [];
    for($i = 0; $i < count($nums); $i++){
        for($j = $i + 1; $j < count($nums); $j++){
            if($nums[$i] + $nums[$j] == $target){
                $result = [$i,$j];
            }
        }
    }
    return $result;
}
```