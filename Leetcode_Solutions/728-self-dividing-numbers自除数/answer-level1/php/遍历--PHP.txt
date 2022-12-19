### 解题思路
此处撰写解题思路

### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了15.38%的用户
内存消耗 :15.1 MB, 在所有 PHP 提交中击败了50.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $left
     * @param Integer $right
     * @return Integer[]
     */
    function selfDividingNumbers($left, $right) {
        $res = [];
        for ($i = $left; $i <= $right; $i++) {
            $flag = true;
            $i = strval($i);
            for ($j = 0; $j < strlen($i); $j++) {
                if ($i[$j] == '0' || $i % $i[$j] != 0) {
                    $flag = false;
                    break;
                }
            }

            if ($flag == true) $res[] = $i;
        }

        return $res;
    }
}
```