### 解题思路
主要思路是遍历数组。先用str_split把字符串转数组，然后遍历每一位。特殊的那几种解法比如IX，正常是11，但结果是9；IV正常是6，结果是4.以此类推发现结果都与正常值相差两倍，所以IV/IX/XL/XC/CD/CM 这几种特殊情况的正确值都是正常遍历加出来的值减去两倍的差。
执行用时 :28 ms, 在所有 PHP 提交中击败了43.20%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了48.48%的用户
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $map=array("I"=>1,"V"=>5,'X'=>10,'L'=>50,'C'=>100,'D'=>500,'M'=>1000);
        $s_array=str_split($s);
        $return_str="";
        foreach($s_array as $key=>$value){
            switch($value){
                default:
                    $return_str+=$map[$value];
                    break;
                case $value=="I" && $s_array[$key+1]=="X":
                    $return_str+=$map[$value]-2;    //1×2
                    break;
                case $value=="I" && $s_array[$key+1]=="V":
                    $return_str+=$map[$value]-2;    //1×2
                    break;
                case $value=="X" && $s_array[$key+1]=="L":
                    $return_str+=$map[$value]-20;    //10×2
                    break;
                case $value=="X" && $s_array[$key+1]=="C":
                    $return_str+=$map[$value]-20;    //10×2
                    break;
                case $value=="C" && $s_array[$key+1]=="D":
                    $return_str+=$map[$value]-200;    //100×2
                    break;
                case $value=="C" && $s_array[$key+1]=="M":
                    $return_str+=$map[$value]-200;    //100×2
                    break;

            }
            
        }
        return $return_str;
    }
}
```