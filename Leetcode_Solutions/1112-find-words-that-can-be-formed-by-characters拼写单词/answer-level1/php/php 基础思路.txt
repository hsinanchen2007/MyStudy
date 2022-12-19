### 解题思路
先将chars做成关联数组，每次循环words去关联数组里查找

### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $len = strlen($chars);
        $char = [];
        for($i=0; $i <= $len-1; $i++){
            if(isset($char[$chars[$i]])){
                $char[$chars[$i]]+=1;
            } else {
                $char[$chars[$i]] = 1;
            }
        }

        $count = 0;
        foreach($words as $word){
            $str = 1;
            $wordLen = strlen($word);
            $forChar = $char;
            for($i=0; $i<=$wordLen - 1; $i++){
                if(isset($forChar[$word[$i]]) and ($forChar[$word[$i]] > 0)){
                    $forChar[$word[$i]] -= 1;
                } else {
                    $str = 0; 
                    break;
                }
            }
            if($str == 1){
                $count += $wordLen;
            }
        }
        return $count;
    }
}
```