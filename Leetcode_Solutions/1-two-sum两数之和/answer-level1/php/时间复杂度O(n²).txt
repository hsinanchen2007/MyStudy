### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $len = count($nums);
        for ($i = 0; $i<$len;$i++)  {
            $first_value = $nums[$i];
            for($j = $i+1;$j < $len;$j++) {
                if($target == ($first_value + $nums[$j])) {
                    return [$i,$j];
                }
            }
        }
    }
}
```