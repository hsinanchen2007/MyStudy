### 解题思路
一个是官方的水平扫描法
一个是暴力比对法

### 代码

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs)
    {
        $prefix = array_shift($strs);
        if (empty($prefix)) {
            return '';
        }
        foreach ($strs as $str) {
            while (!(strstr($str, $prefix) && strpos($str, $prefix) == 0)) {
                $prefix = substr($prefix, 0, strlen($prefix) - 1);
                if ($prefix == '') return '';
            }
        }
        return $prefix;
    }
}


function longestCommonPrefix($strs)
{
    $first = array_shift($strs);
    $str = '';
    for ($i = 0; $i < strlen($first); $i++) {
        foreach ($strs as $value) {
            if ($first[$i] != $value[$i]) {
                return $str;
            }
        }
        $str .= $first[$i];
    }
    return $str;
}
```