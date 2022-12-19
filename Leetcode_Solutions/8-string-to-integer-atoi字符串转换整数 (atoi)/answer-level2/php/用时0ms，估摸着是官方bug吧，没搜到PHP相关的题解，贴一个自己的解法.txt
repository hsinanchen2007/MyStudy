
```
    function myAtoi($str) {
        //首先去除str中的左侧空格;
        $str = ltrim($str,' ');
        $resStr = '';
        $max = pow(2,31)-1;
        $min = 0 - pow(2,31);
        if($str{0}!='-' && $str{0}!='+' && !is_numeric($str{0})){
            return 0;
        }elseif(($str{0}=='-'||  $str{0}=='+')&& !is_numeric($str{1})){
            return 0;
        }elseif($str{0}=='-'||  $str{0}=='+'){
            if($str{0}=='-'){
                $resStr = '-';
                $str = ltrim($str,'-');

            }else{
                $str = ltrim($str,'+');
            }

        }
        $i=0;
        $len = strlen($str);
        while ($i<$len){
            if(is_numeric($str{$i})){
                $resStr .= $str{$i};
            }else{
                break;
            }
            $i++;
        }
        $resStr = intval($resStr);
        if($resStr>$max){
            return $max;
        }
        if($resStr < $min){
            return $min;
        }
        return $resStr;
    }
```

