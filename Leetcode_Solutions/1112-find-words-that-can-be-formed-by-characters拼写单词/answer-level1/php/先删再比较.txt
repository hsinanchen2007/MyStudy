### 解题思路
找到并替换

### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $sum = 0;
        for($i=0;$i<count($words);$i++){
            $temp = $chars;//make a copy of current chars
            $l = strlen($words[$i]);
            for($j=0;$j<$l;$j++){
                $key = strpos($temp,$words[$i][$j]);//return the char position
                if($key === false) break;//if key is not found, break
                $temp = substr_replace($temp,'',$key,1);//remove the char from chars
            }
            if($j == $l) $sum += $l;//if size of j increased to the same of l, then found the word
        }
        return $sum;
    }
}
```