### 解题思路
判断当前参数是否大于0  大于0反转当前数 做判断
不大于0 反转当前数 在做判断

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        if ($x>0) {
            $dat = strrev($x);
        }else{
            $dat = strrev($x);
        }
        if ($dat == $x) {
            return true;
        }else{
            return false;
        }
    }
}
```