遍历判断数组
```
class Solution {

    /**
     * @param String $text
     * @param String $first
     * @param String $second
     * @return String[]
     */
    function findOcurrences($text, $first, $second) {
        $te_arr = explode(" ", $text);
      //  var_dump($te_arr);
        $rep = [];
        foreach($te_arr as $rk=>$rv) {
            if($rv == $first && $te_arr[$rk+1] == $second) {
                if (isset($te_arr[$rk+2])) {
                     $rep[] = $te_arr[$rk+2];
                }
            }
        }
     //   var_dump($rep);
        return $rep;
    }
}
```
