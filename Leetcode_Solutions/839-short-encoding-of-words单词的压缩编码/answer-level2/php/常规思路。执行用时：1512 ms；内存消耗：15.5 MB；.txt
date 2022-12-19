### 解题思路
判断要插入的单词是否存在，存在就不插入；不存在就判断子串是否存在，不存在就追加，存在就替换


### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    function minimumLengthEncoding($words)
    {
        $str = '#';
        foreach ($words as $word)
        {
            $pos = strpos($str,$word.'#');
            if($pos===false)
            {
                $len = strlen($word);
                $is_find = false;
                for($i=1;$i<$len;$i++){
                    $sub = '#'.substr($word,$i).'#';
                    if(strpos($str,$sub)!==false){
                        $is_find = true;
                        break;
                    }
                }
                if($is_find){
                    $str = str_replace($sub,"#$word#",$str);
                }else{
                    $str .= "$word#";
                }
            }else{
                continue;
            }
        }
        return strlen($str)-1;
    }
}
```