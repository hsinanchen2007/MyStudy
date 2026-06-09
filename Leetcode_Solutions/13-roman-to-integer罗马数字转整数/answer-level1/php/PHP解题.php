执行用时 : 40 ms, 在Roman to Integer的PHP提交中击败了98.99% 的用户
内存消耗 : 15 MB, 在Roman to Integer的PHP提交中击败了6.16% 的用户

```
<?php

class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $map = [
            "I"=>1,
            "V"=>5,
            "X"=>10,
            "L"=>50,
            "C"=>100,
            "D"=>500,
            "M"=>1000
        ];
        $map2 = [
            "IV"=>4,
            "IX"=>9,
            "XL"=>40,
            "XC"=>90,
            "CD"=>400,
            "CM"=>900
        ];
        
        $nums = [];
        foreach ($map2 as $str=>$number ){
            if(strpos($s,$str) !== false){
                $nums[] = $number;
                $s = str_replace($str,"",$s);
            }
        }
        unset($str,$str);
        $bytes = str_split($s);
        foreach($bytes as $key=>$str){
            
            if( isset($map[$str])){
                $nums[] = $map[$str];
            }
        }
        return array_sum($nums);
    }
}


$obj  = new Solution();
echo $obj->romanToInt(III); //MCMXCIV
```