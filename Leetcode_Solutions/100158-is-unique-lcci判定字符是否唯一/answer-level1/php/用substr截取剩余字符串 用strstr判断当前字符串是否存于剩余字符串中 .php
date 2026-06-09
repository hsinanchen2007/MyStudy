### 解题思路


### 代码

```php
class Solution {

    /**
     * @param String $astr
     * @return Boolean
     */
    function isUnique($astr) {
        $count = strlen($astr);
        for($i=0;$i<$count;$i++)
        {
           if(strstr(substr($astr,$i+1),$astr[$i])){
               return false;
           };

        }
    return true;
    }
}
```