执行用时 :
8 ms
, 在所有 PHP 提交中击败了
100.00%
的用户
内存消耗 :
14.3 MB
, 在所有 PHP 提交中击败了
97.95%
的用户

class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $arr = ['I'=>1,'V'=>5,'X'=>10,'L'=>50,'C'=>100,'D'=>500,'M'=>1000];
        $res = 0;
        for($i=0;$i<strlen($s);$i++){
            if(!isset($arr[$s[$i+1]]) || $arr[$s[$i]] >= $arr[$s[$i+1]]){
               $res += $arr[$s[$i]];
            }else{
               $res +=$arr[$s[$i+1]] - $arr[$s[$i]];
               $i = $i+1;
            }
        }
           return $res;
    }
}