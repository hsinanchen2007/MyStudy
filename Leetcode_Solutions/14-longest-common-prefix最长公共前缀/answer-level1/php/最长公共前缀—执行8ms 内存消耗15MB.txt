### 解题思路
除去空数组和长度为1的数组，从数组中第一个元素开始的第一个字母开始与后面的元素相同位置的字母对比，当出现不同或已经对比到第一个元素最后一个位仍未出现不同字母时，返回第一个元素当前长度的字符串

### 代码

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        foreach ($strs as $ke=>$value) {
            if ($value == '') {
                return '';
            }
        }
        if (count($strs)==1){
            return $strs[0];
        }        
        $len = strlen($strs[0]);
        $i = 0;
        while ($i<=$len) {
            $str =  substr($strs[0],$i,1);
            for ($j = 1; $j < count($strs); $j++) {
                if ($str != substr($strs[$j],$i,1) or $i==$len) {                    
                    return substr($strs[0],0,$i);
                }
            }
            $i++;
        }
        return '';
    }
}
```