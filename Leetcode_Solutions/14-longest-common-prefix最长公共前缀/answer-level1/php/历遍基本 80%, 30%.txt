### 解题思路
历遍一个一个字符找，一轮结束还没崩就把当前字符加上去

### 代码

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        if(empty($strs)) return "";
        $prefix = '';
        $i = 0;

        //一个字母一个字母历遍，如果每个单词同一位置字母皆相同，则把该字母加入前缀
        //否则如果某个单词相同位置字母不同则退出，返回前缀
        while(true){
            $current = $strs[0][$i];
            if(!$current){
                return $prefix;
            }
            foreach($strs as $str){
                if($str[$i] != $current){
                    return $prefix;
                }
            }
            $prefix .= $current;
            $i++;
        }
        return $prefix;
    }
}
```