### 解题思路
看代码

### 代码

```php
class Solution {

    /**
     * @param String $pattern
     * @param String $str
     * @return Boolean
     */
    function wordPattern($pattern, $str) {
        // 切割字符串
        $strArr = explode(" ", $str);
        // 长度不同 返回false
        if (strlen($pattern) !=  count($strArr) ) {
            return false;
        }
        // 切割字符串
        $patternArr = str_split($pattern);

        $patternMap = [];
        $strMap = [];
        // 保存每个字母的位置
        foreach($patternArr as $key => $value) {
            $patternMap[$value][] = $key;
        }
        // 保存每个单词的位置
        foreach($strArr as $key => $value) {
            $strMap[$value][] = $key;
        }
        // 去掉key
        $patternMap = array_values($patternMap);
        $strMap = array_values($strMap);
        // 循环比较位置
        foreach ($patternMap as $key => $value) {
            if ($value != $strMap[$key]) {
                return false;
            }
        }
        return true;
    }
}
```