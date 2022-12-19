### 解题思路

将字符串分隔成字母数组，并统计字符串中每个字母的个数。

### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $length = 0;
        $chars_count_arr = array_count_values(str_split($chars));
        foreach($words as $v){
            $v_count_arr = array_count_values(str_split($v));
            $stat = true;
            foreach($v_count_arr as $w_k => $w_v){
                if(!isset($chars_count_arr[$w_k]) || $w_v > $chars_count_arr[$w_k]){
                    $stat = false;
                    break;
                }
            }
            $stat === true && $length += strlen($v);
        }
        return $length;
    }
}
```