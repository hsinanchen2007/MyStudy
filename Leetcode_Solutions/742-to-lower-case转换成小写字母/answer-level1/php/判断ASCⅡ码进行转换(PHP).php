转换成数组进行遍历判断，将大写字母转小写，之后再转成字符串。
```
class Solution {

    /**
     * @param String $str
     * @return String
     */
    function toLowerCase($str) {
        if(empty($str))return "";
        $arr = str_split($str,1);
        foreach($arr as $k => &$v){
            $ac = ord($v);    
            // 大写字母转小写
            if($ac >=65 && $ac <= 90 ){
                $v = chr($ac + 32);
            }
            
        }
        return implode($arr);
    }
}
```

