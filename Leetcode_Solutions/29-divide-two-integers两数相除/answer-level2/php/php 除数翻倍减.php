### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/1f3d0e781bfaa5e4bec7ee4a4a8c6cb032f104c5fbd1afc3ae9cb3f1179089b9-image.png)


### 代码

```php
class Solution {

    /**
     * @param Integer $dividend
     * @param Integer $divisor
     * @return Integer
     */
    function divide($dividend, $divisor) {
        $ans = 0;
        $neg = $dividend > 0 && $divisor < 0 || $dividend < 0 && $divisor > 0;
        
        $dividend = $dividend > 0 ? $dividend : 0 - $dividend;
        $divisor = $divisor > 0 ? $divisor : 0 - $divisor;

        while($dividend >= $divisor) {
            $p = $divisor;
            $pow = 1;
            while ($p <= $dividend) {
                $dividend -= $p;
                $ans += $pow;
                $p += $p;
                $pow += $pow;
            }
        }
        
       !$neg && $ans >= (1 << 31) && $ans = (1 << 31) - 1;
        
        return $neg ? 0 - $ans : $ans;
    }
}
```