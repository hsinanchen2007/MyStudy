### 解题思路
除以4，如果余数为0，就继续除，直到余数不为0 ，如果最终是1就是true, 否则false。

不明白技巧解决的意义何在

注意：能整除4的不一定就是，比如20
开始想当然写成了
```
        if ($num == 1 OR ($num > 1 && $num % 4 == 0)) {
            return true;
        } else {
            return false;
        }
```


### 性能
执行用时 :4 ms, 在所有 php 提交中击败了96.00%的用户
内存消耗 :14.7 MB, 在所有 php 提交中击败了33.33%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Boolean
     */
    function isPowerOfFour($num) {
        if ($num < 1) {
            return false;
        }

        while ($num % 4 == 0) {
            $num /= 4;
        }
        
        return $num == 1;
    }
}
```