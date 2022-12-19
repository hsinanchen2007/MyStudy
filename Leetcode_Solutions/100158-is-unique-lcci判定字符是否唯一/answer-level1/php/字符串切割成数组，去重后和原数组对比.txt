### 解题思路
1. 字符串切割成数组`str_split`
2. 数组做去重处理`array_unique`
3. 比较去重前后的数组是否相等

### 代码

```php
class Solution {

    /**
     * @param String $astr
     * @return Boolean
     */
    function isUnique($astr) {
        $arr = str_split($astr);
        $arr1 = array_unique($arr);
        if ($arr != $arr1) {
            return false;
        }
        return true;
    }
}
```