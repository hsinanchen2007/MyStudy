### 解题思路
排序

### 性能
执行用时 :108 ms, 在所有 PHP 提交中击败了20.00%的用户
内存消耗 :17.1 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return String[]
     */
    function findRelativeRanks($nums) {
        $st_nums = $nums;
        rsort($st_nums);

        $res = [];
        for ($i = 0; $i < count($nums); $i++) {
            $pos = array_keys($st_nums, $nums[$i])[0];
            switch ($pos) {
                case 0:
                    $res[] = 'Gold Medal';
                    break;
                case 1:
                    $res[] = 'Silver Medal';
                    break;
                case 2:
                    $res[] = 'Bronze Medal';
                    break;
                default:
                    $res[] = strval($pos + 1);
                    break;
            }
        }

        return $res;
    }
}
```