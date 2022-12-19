### 解题思路
全靠函数搞出来的，提交了7次才提交成功

### 代码

```php
class Solution {

    /**
     * @param String $str
     * @return Integer
     */
    function myAtoi($str) {
        $str = trim($str);
        $arr = str_split($str);
        $res = [];
        $flag = $strcount =  0;
        foreach ($arr as $key => $val){
            if(is_numeric($val)){
                $res[] = $val;
            }
            else if ($strcount == 0 && in_array($val,['+','-'])){
                if($val == '-'){
                    $flag = 1;
                }
            }else{
                break;
            }
            $strcount += 1;
        }
        $count = intval(implode('',$res));
        if(empty($count)){
            return 0;
        }
        if($flag == 1){
            $count = -$count;
        }
        $min = -pow(2,31);
        $max = pow(2,31) - 1;
        if($count < $min){
            $count = $min;
        }
        if($count > $max){
            $count = $max;
        }

        return $count;
    }
}
```