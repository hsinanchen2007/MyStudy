### 解题思路
字符串转数组，获取 needle 第一个元素在 haystack 中的位置，在保证从该位置开始往后的长度不小于 needle 的长度的情况下，将这些位置记录在一个指定数组 leng 中，最后个根据 leng 以及 needle 的长度，截取 haystack。对比截取后的字符串是否与 needle相同，返回此时 leng 的值

### 代码

```php
class Solution {

    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        if ($needle == null || $haystack == $needle) {
            return '0';
        }
        $haystacka = str_split($haystack);
        $needlea = str_split($needle);
        $leng = array();
        for ($i = 0; $i < count($haystacka); $i++) {
            if ($needlea[0] == $haystacka[$i] && $i+count($needlea)<=count($haystacka)) {
                array_push($leng, $i);
            }            
        }
        foreach ($leng as $key => $value) {
            $newhay = substr($haystack, $value,count($needlea));
            if ($needle == $newhay) {
                return $value;
            }
        }
        return '-1';
    }
}
```