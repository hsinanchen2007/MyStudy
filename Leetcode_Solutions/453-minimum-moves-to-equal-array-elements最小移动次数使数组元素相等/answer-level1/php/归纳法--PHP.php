### 解题思路
转换思路，每次移动最大数，其他每个数加1，等价于每次让除了最小数外的一个减一。把每个数跟最小数的差值加和即可。

### 性能
执行用时 :104 ms, 在所有 PHP 提交中击败了53.85%的用户
内存消耗 :16.5 MB, 在所有 PHP 提交中击败了25.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function minMoves($nums) {
        $times = 0;
        $min = min($nums);
        for ($i = 0; $i < count($nums); $i++) {
            $times += $nums[$i] - $min;
        }

        return $times;
    }
}
```