### 解题思路
主要解题思路：取多维数组的第一个元素作为默认公共前缀，遍历数组其他元素进行匹配，发现不匹配情况，则进行字符串截取。遍历完多维数组所有元素后，剩余字符串为公共前缀结果值。
需要注意的几个踩坑点：
1. 数组中只存在一个元素时，则返回其本身；
2. 不要直接操作第一个元素，防止$length值被重置的情况；
3. 每遍历数组中下一个元素后，即根据$length剪切其$ret值。

### 代码

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        $ret = "";

        if(empty($strs)) return $ret;
        $strFirst = array_shift($strs);
        if(empty($strs)) return $strFirst;

        $ret = $strFirst;
        foreach($strs as $strVal){
            $length = 0;
            for($i=0; $i<strlen($strFirst); $i++){
                if(isset($strVal[$i]) && $strVal[$i] == $strFirst[$i]){
                    $length = $i+1;
                } else {
                    break;
                }
            }

            $ret = substr($ret, 0, $length);
            if(empty($ret)){
                return $ret;
            }
        }
        return $ret;
    }
}
```