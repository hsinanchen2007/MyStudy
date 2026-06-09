 n为偶数，数组添加以0为中心的对称数字，正好为偶数个，和必然为0
 n为奇数，添加n-1个对称数字之后，再加一个0即可



function sumZero($n) {

            $arr = array();
            $index = 0;
            for($i=1;$i<=$n/2;$i++){
                $arr[$index++] = -$i;
                $arr[$index++] = $i;
            }

            if(count($arr)<$n){
                $arr[] = 0;
            }

            return $arr;
    }