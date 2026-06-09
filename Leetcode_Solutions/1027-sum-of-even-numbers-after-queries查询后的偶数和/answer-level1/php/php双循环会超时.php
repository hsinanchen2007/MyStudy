```
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer[][] $queries
     * @return Integer[]
     */
    function sumEvenAfterQueries($A, $queries) {
        //双循环会超时
         //$c1 = count($queries);
         // $arr = [];
         // for ($i = 0;$i<$c1; $i++) {
         //    $val = $queries[$i][0];
         //    $index = $queries[$i][1];
         //    $A[$index] = $A[$index] + $val;   
         //    $sum = 0;
         //    foreach($A as $v){
         //        if($v%2 === 0) $sum += $v;
         //    } 
         //    array_push($arr,$sum); 
         // }
         //    return $arr;
        //answer 0
            $c1 = count($queries);
            $val = $queries[0][0];
            $index = $queries[0][1];
            $A[$index] = $A[$index] + $val;   
            $sum = 0;
            foreach($A as $v){
                if($v%2 === 0) $sum += $v;
            }
            $answer[0] = $sum;
            for ($i = 1;$i<$c1; $i++) {
            $val = $queries[$i][0];
            $index = $queries[$i][1];
            if (($A[$index]%2 === 0) && ($val%2 === 0)) {
                $answer[$i] =  $answer[$i-1] +  $val;
            }  elseif(($A[$index]%2 === 0)) {
                $answer[$i] =  $answer[$i-1] -  $A[$index];
            }  elseif(($val%2 === 0)) {
                $answer[$i] =  $answer[$i-1];
            } else {
                $answer[$i] =  $answer[$i-1] +  $val + $A[$index];
            }
            $A[$index] = $A[$index] + $val;

         }
            return $answer;
            
    }
}
```
