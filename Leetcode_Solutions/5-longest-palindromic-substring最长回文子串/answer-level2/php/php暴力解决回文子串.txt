### 解题思路
php暴力比对

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function longestPalindrome($s) {
    $strlen=strlen($s);
    $maxlen=0;
    $maxstr='';
    for ($i=0;$i<$strlen;$i++){
        if($maxlen>$strlen-$i)break;    //对于超长的回文子串，有很好的“功效”
        for ($j=$strlen-$i;$j>0;$j--){
            $str=substr($s,$i,$j);
            if (strrev($str)===$str&&$maxlen<strlen($str)){
                $maxlen=strlen($str);
                $maxstr=$str;
            }
        }
    }
    return $maxstr;
}

}

```