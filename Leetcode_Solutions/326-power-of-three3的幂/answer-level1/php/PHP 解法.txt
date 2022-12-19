### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function isPowerOfThree($n) {
        if ($n <= 0) {
            return false;
        }

        while ($n % 3 == 0) {
            $n = $n / 3;
        }

        return $n == 1;
    }
}
```