结题思路：
1. 已知罗马字符的值都是1,4,5,9的整十数倍，且组合成同级位数的方式相同，例如 
```
7：5+1+1=>VII; 
70:50+10+10=>LXX;
```
2. 我们将罗马数字的表示方式和每位整数对应的罗马字符的计算方式抽象出来；
3. 逐个计算每一位整数对应的罗马字符，按照顺序拼接起来即为所求；

代码如下，注释详细：
```
class Solution {
    
    #罗马数字字符集
    protected $char_list = [
            [1=>'I', 4=>'IV', 5=>'V', 9=>'IX'], # 个位
            [1=>'X', 4=>'XL', 5=>'L', 9=>'XC'], # 十位
            [1=>'C', 4=>'CD', 5=>'D', 9=>'CM'], # 百位
            [1=>'M'] # 千位
        ];

    /**
     * @param Integer $num
     * @return String
     */
    function intToRoman($num) {
        $res_str = '';
        $i = 0;
        while($num>0) {
            $temp_num = $num%10;
            $temp_char = $this->caclDigitToRoman($i, $temp_num); # 计算当前位的数字的罗马字符；
            $res_str = $temp_char . $res_str; # 从低位计算，字符拼接到结果字符串的左边；
            $num = intval($num/10);
            $i++;
        }
        return $res_str;
    }
    
    # 计算每位数字对应的罗马字符
    /**
    * 算法逻辑：除千位，其他位数的值范围是1-9，组成分三种情况：n个1、n个1与5的组合，已定义数字；
    * @param Integer $pos
    * @param Integer $digit
    */
    function caclDigitToRoman($pos, $digit) {
        $res = '';
        $row = $this->char_list[$pos];
        if(isset($row[$digit])) {
            return $row[$digit];
        } elseif($digit>5) {
            $res = $row[5];
            $digit = $digit-5;
        }  
        if($digit>0){
            for($i=0; $i<$digit; $i++) {
                $res .= $row[1];
            }
        }
        return $res;
    }
}
```
