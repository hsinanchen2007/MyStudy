### 解题思路
1. $j按照顺序在$nums塞非零数据；
2. $i != $j 时，将$nums[$i] 置为0；

### 代码

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        $j = 0;
        for($i = 0; $i < count($nums); $i++) {
            if($nums[$i] !== 0) {
                $nums[$j] = $nums[$i];
                if($i != $j) {
                    $nums[$i] = 0;
                }
                ++$j;
            }
        }
        return $nums;
    }
}
```