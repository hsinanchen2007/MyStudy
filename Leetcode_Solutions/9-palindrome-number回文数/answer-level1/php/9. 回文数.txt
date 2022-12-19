### 解题思路
如果转化为字符串是比较简单的
先判断是否小于0，小于零直接返回false
如何用输入的$x与反转后的$x对比相同返回true即可

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        if ($x < 0){
            return false;
        }

        if ($x == strrev($x)){
            return true;
        }

        return false;
    }
}
```