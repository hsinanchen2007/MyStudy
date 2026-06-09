### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @param Integer $length
     * @return String
     */
    function replaceSpaces($S, $length) {
        
        return str_replace(' ','%20',substr($S,0,$length));
    }
}
```