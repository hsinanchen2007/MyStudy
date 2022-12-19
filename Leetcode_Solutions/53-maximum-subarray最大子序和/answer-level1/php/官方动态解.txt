### 解题思路
分治法没看懂，只有动态的看懂了

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxSubArray($nums) {
        // if (empty($nums)) {
        //     return 0;
        // }

        // $sum = $nums[0];
        // $dp = $nums[0];
        // for($i = 1; $i < count($nums); ++$i) {
        //     $dp = max($nums[$i], $nums[$i] + $dp);
        //     $sum = max($sum,$dp);
        // }
        // return $sum;

        for($i=1;$i<count($nums);$i++) $nums[$i] = max($nums[$i],$nums[$i]+$nums[$i-1]);
        return max($nums);
    }
}
```