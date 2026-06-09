### 解题思路
其实就是每两个一对，小的放一组

### 性能
执行用时 :128 ms, 在所有 PHP 提交中击败了79.66%的用户
内存消耗 :17.9 MB, 在所有 PHP 提交中击败了8.33%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function arrayPairSum($nums) {
        sort($nums);
        $sum = 0;
        for ($i = 0; $i < count($nums); $i += 2) {
            $sum += $nums[$i];
        }

        return $sum;
    }
}
```