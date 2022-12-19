```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $tem_arr = str_split($s);  //将字符串分割为数组
        $tem_arr_count = array_count_values($tem_arr);  //统计数组中所有的值数量
        $len = 0;
        $old_arr = array();  //数量为奇数的数组
        foreach($tem_arr_count as $key => $value){
            //偶数可直接取，奇数单独保存到奇数数组
            if($value % 2 == 0){
                $len += $value;
            }else{
                $old_arr[$key] = $value; 
            }
        }
        foreach($old_arr as $oldnum){
            $len += $oldnum - 1;   //如果为奇数的话，可以拿到他的最大偶数来拼接回文字符串的，所以这里减1就为最大长度
        }
        if($old_arr){
            $len = $len + 1;   //有奇数个数的话，回文字符串中间的字符单个就回文了，所以加最中间的一个长度
        }
        return $len;
    }
}
```
