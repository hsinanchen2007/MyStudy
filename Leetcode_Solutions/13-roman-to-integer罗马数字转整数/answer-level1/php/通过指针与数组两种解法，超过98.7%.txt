class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        // 通过字符串当做数组进行遍历
        // $rome = ["I"=>1, 'V'=>5, 'X'=>10, 'L'=>50, 'C'=>100, 'D'=>500, 'M'=>1000];
        // $len = strlen($s);
        // $sum = 0;
        // for($i=0; $i<$len; $i++){
        //     $sum += $rome[$s[$i]];
        //     if($i>=1 && ($rome[$s[$i-1]] < $rome[$s[$i]])){
        //         $sum -= $rome[$s[$i-1]]*2;
        //         if($i>=2 && ($rome[$s[$i-2]] < $rome[$s[$i-1]])){
        //             $sum -= $rome[$s[$i-2]]*2;
        //         }
        //     }
        // }
        // return $sum;

        // 通过指针来遍历数组
        $rome = ["I"=>1, 'V'=>5, 'X'=>10, 'L'=>50, 'C'=>100, 'D'=>500, 'M'=>1000];
        $arr = str_split($s);
        $sum = 0;
        do{
            $sum += $rome[current($arr)];
            if(key($arr)>=1){
                $cur = $rome[current($arr)];
                prev($arr);
                if($rome[current($arr)] < $cur){
                    $sum -= $rome[current($arr)]*2;
                    if(key($arr)>=1){
                        $cur = $rome[current($arr)];
                        prev($arr);
                        if($rome[current($arr)] < $cur){
                            $sum -= $rome[current($arr)]*2;
                        }
                        next($arr);
                    }
                }
                next($arr);
            }
        }while(next($arr));
        return $sum;
    }
}