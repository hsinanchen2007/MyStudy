### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $astr
     * @return Boolean
     */
    function isUnique($astr) {
        $len = strlen($astr);
        for ($i=0;$i<$len;$i++) {
            for ($j=$len-1;$j>=0;$j--) {
                if ($astr[$i] == $astr[$j] && $i != $j) {
                    return false;
                } 
            }
        }
        return true;
    }
}
```