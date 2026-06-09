### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $a
     * @param Integer $b
     * @param Integer $c
     * @return Integer
     */
    function minFlips($a, $b, $c) {
        $result = 0;
        for($i=0;$i<31;$i++){
            $bita_i = (($a >> $i) & 1);
            $bitb_i = (($b >> $i) & 1);
            $bitc_i = (($c >> $i) & 1);
            if($bitc_i == 0){
                $result+= ($bita_i+$bitb_i);
            }else{
                $result+= ($bita_i+$bitb_i)==0;
            }
        }
        return $result;
    }
}
```