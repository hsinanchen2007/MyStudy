用双指针，前后遍历是否存在元音字母，没有则继续推进，直至找到元音字母。
当两个指针都找到元音字母，交换之。
重复流程直到遍历完成。

```
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseVowels($s) {
        $len = strlen($s);
        if($len <= 1){
            return $s;
        }
        $i = 0;
        $j = $len - 1;
        $char = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
        
        while($i < $j){
            while($i < $j && !in_array($s[$i], $char)) $i++;
            while($i < $j && !in_array($s[$j], $char)) $j--;
            if ($i < $j){
                $tmp = $s[$i];
                $s[$i++] = $s[$j];
                $s[$j--] = $tmp;
            }
        }
        return $s;
    }
}
```
