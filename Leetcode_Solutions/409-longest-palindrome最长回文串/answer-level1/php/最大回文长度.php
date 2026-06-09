### 解题思路
因为不需要找出具体内容，区分字符数量为偶数和奇数的情况，偶数直接加，奇数的话，要减1后再加，最后根据是否有奇数再补1

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $ret=0;
        $odd=0;
        $hash=array();
        for($i=0;$i<strlen($s);$i++){
            $hash[$s[$i]]++;
        }
        foreach($hash as $num){
            if($num%2==0){
                $ret+=$num;
            }else{
                $odd=1;
                $num--;
                $ret+=$num;
            }
        }

        return $ret+$odd;
        
    }
}
```