提供一个思路，虽然很慢。。。
```
class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
         $len= strlen($s);
         if($len<=$numRows||$numRows==1){
            return $s;
         }
         $a = [];
         for($j =0; $j<$numRows;$j++){
              $a[$j] = [];
         }
         $j = 0;
         for($i = 0 ; $i<$len;$i++){
             if($j>$len-1){
                break;
             }
            for($k=0;$k<$numRows;$k++){
                if($j>$len-1){
                    break;
                }
                $a[$k][$i]="";
                $b= ($i)%($numRows-1);
                if($b==0){
                    $a[$k][$i]=$s[$j];
                    $j++;
                }elseif($numRows == $k+$b+1){
                    $a[$k][$i]=$s[$j];
                    $j++;
                }
             }
        }
        $str = '';
        for ($j = 0; $j <= $numRows; $j++) {
            $str .= implode('', $a[$j]);
        }

        return $str;
    }
}
```
