### 解题思路
一遍写成，不调试，直接提交

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了12.24%的用户
内存消耗 :18.1 MB, 在所有 PHP 提交中击败了64.29%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return String[]
     */
    function fizzBuzz($n) {
        $res = [];
        for ($i = 1; $i <= $n; $i++) {
            if ($i % 3 == 0 && $i % 5 == 0) {
                $res[] = 'FizzBuzz';
            } elseif ($i % 3 == 0) {
                $res[] = 'Fizz';
            } elseif ($i % 5 == 0) {
                $res[] = 'Buzz';
            } else {
                $res[] = "$i";
            }
        }

        return $res;
    }
}
```