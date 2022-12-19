### 解题思路
首尾相比,一直比

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        $x = $x . "";
        $e = strlen($x);
        for($b = 0;$b < $e;$b++){
            if($x[$b] != $x[$e - $b - 1] ){
                return false;
            }
        }
        return true;
    }
}
```