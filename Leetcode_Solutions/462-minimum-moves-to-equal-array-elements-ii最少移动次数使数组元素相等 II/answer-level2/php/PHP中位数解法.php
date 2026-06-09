### 解题思路
中位数思想，排序用php内置的即可

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function minMoves2($nums) {
        sort($nums);
        $cnt = 0;
        $len = count($nums);
        $midIndex = intval($len/2);
        $mid = $nums[$midIndex];
        foreach($nums as $val){
            $cnt += abs($val - $mid);
        }
        return $cnt;
    }
}
```