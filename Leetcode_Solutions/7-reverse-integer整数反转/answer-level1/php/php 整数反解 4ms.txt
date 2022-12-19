    
     执行时间4ms

     function reverse($x) {
        $x = (string)$x;
        $ret = is_numeric($x[0])?(int)strrev($x):-strrev(abs($x));
        if( $ret >= -2147483648 && $ret <= 2147483648){
            return $ret;
        }else{
            return 0;
        }
    }