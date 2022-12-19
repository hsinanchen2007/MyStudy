### 解题思路
此处撰写解题思路
1》s1 = 过滤原始字符串中不是数字、字母的其他字符，如空格、其他特殊符号等
2》s2 = 将处理过得字符串进行翻转
3》s1 与 s2 进行比较，如果两字符串相同，则返回true, 不相同则返回false
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isPalindrome($s) {
        $s1 = $this->_filterNonNumberAndChar($s);
        $s2 = strrev($s1);
        if (strcmp($s1, $s1)){
            return false;
        } else {
            return true;
        }
    }

    function _filterNonNumberAndChar($str){
        $str = str_replace(' ','',$str);
        $str = strtolower(preg_replace('/[^a-z0-9]/i','',$str));
        return $str;
    }
}
```