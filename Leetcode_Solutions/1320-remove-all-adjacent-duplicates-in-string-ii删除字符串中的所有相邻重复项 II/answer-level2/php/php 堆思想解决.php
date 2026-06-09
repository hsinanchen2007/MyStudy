堆的思想先进后出；灵感，之前看过一个视频讲 判断括号的配对问题；
$count 变量用来存储字母计数情况 k是字母 v是计数；
字符串依次入堆，如果计数达到K次 则出堆k个元素；



 function removeDuplicates($s, $k) {
        $str = '';
        $count =[];
        
        for($i=0;$i<strlen($s);$i++){
            $j = count($count)-1;
            if($i!=0&&$count[$j]['k'] == $s[$i]){
                $count[$j]['v']=$count[$j]['v']+1;
                if($count[$j]['v']==$k){
                    //重复满足
                    $len= strlen($str);
                    $str=substr($str,0,$len-$k+1);
                    array_pop($count);
                }else{
                    $str.=$s[$i];

                }
            }else{

                $str.=$s[$i];
                $count[]=['k'=>$s[$i],'v'=>1];

            }

        }
        return $str;
    }