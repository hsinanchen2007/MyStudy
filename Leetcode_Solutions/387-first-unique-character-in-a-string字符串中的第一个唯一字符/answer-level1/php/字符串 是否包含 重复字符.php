### 解题思路
遍历字符串
取每个字符，然后字符串用#替代该字符（去掉来判重）
判断字符串是否包含该字符，如果不包含，说明不重复直接返回索引;若包含，说明重复了，恢复索引值原貌，继续循环
遍历结束 没找到循环重复索引，返回-1
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function firstUniqChar($s) {
        for($i=0;$i<strlen($s);$i++) {
            $ch = $s[$i];
            $s[$i] = '#';
            if(false !== strpos($s, $ch)) {
                $s[$i] = $ch; //存在的话就要改回去
                continue;
            }else{
                return $i;
            }
        }
        return -1;
    }
}
```