### 解题思路
此处撰写解题思路
目前只想到最暴力的方式，两边循环，第一遍循环统计每个字符出现的次数；第二遍循环遇到第一个次数为1的即返回
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function firstUniqChar($s) {
        //思路一
        
        $len = strlen($s);
        $arr = [];
        for ($i = 0; $i < $len; $i ++) {
            $arr[$s[$i]] ++;
        }
        
        for ($i = 0; $i < $len; $i ++) {
            if ($arr[$s[$i]] == 1) {
                return $s[$i];
            }
        }
        return " ";
        
        
        
    }
}
```