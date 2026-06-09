### 解题思路
把字符串分割成数组，判断数组是否有相同元素

### 代码

```php
class Solution {

    /**
     * @param String $astr
     * @return Boolean
     */
    function isUnique($astr) {
        $arr_a = str_split($astr);
        if(count($arr_a) != count(array_unique($arr_a))){
            return false;
        }else{
            return true;
        }
    }
}
```