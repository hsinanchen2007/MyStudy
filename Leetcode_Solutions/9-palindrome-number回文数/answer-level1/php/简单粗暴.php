### 解题思路
简单    粗暴    直接  明了  直接用strrev

### 代码

```php
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        if($x<0){
            return false;
        }
        if(strrev($x) == $x){
            return true;
        }else{
            return false;
        }
    }
}
```