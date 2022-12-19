### 解题思路
利用字符串统计字串出现次数
### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    function minimumLengthEncoding($words) {
        $left_nums = 0;
        $words = array_unique($words);
        $str_words = '#'.implode("#", $words)."#";
        foreach($words as $k=>$w){
            $_count = substr_count($str_words, $w.'#');
            if($_count > 1){
                // 加一次判断，为了避免["time", "atime", "btime"]这种情况而误判为3个重复
                if(substr_count($str_words,'#'.$w.'#')>1)
                    $left_nums = strlen($w.'#')*($_count-1);
                else 
                    $left_nums = strlen($w.'#');
            }
        }
        return strlen($str_words) - $left_nums - 1;
    }
}
```