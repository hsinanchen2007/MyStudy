### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
        $now = 0;
        $new_arr = [];
        for($i = 0; $i<strlen($s);$i++){
            $new_arr[$now][] = $s[$i];
            if($now == $numRows-1){
                $a = "-";
            }
            if($now == 0){
                $a = "+";
            }
            if($a == "-"){
                $now--;
            }
            if($a == "+"){
                $now++;
            }
        }
        $new_s = "";
        foreach($new_arr as $k=>$v){
            $new_s .= implode($v);
        }
        return $new_s;
    }
}
```