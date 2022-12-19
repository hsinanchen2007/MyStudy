### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Float $x
     * @param Integer $n
     * @return Float
     */
    function myPow($x, $n) {
        if ($n > 0) {
            return $this->myPow1($x, $n);
        } else if ($n == 0){
            return 1;
        } else {
            return 1/$this->myPow1($x, -$n);
        }
    }
    function myPow1($x, $n) {
        if ($n == 0) {
            return 1;
        }
        $s = floor($n / 2);
        $half = $this->myPow($x, $s);
        if ($n % 2 == 0) {
            return $half * $half;
        } else {
            return $half * $half * $x;
        }
    }
}
```