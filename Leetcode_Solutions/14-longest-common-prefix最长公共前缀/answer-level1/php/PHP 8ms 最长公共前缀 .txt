
    
function longestCommonPrefix($strs) {
        //1、获取数组里最短字符串的长度
        $min = min(array_map(function($v){
            return strlen($v);
        },$strs));
        //2、数组的长度
        $len = count($strs);
        $j = 0;
        $p = '';
        do{
            $tmp = [];
            for($i = 0;$i<$len;$i++){            
                $tmp[] = $strs[$i][$j];//循环将数组的每个值的$j位置的数放到临时数组 $strs[0][0] ,$strs[1][0],$strs[2][0]
            }
            //如果排重后数组长度等于1说明==
            if(count($s = array_unique($tmp)) == 1){
                $p .= $s[0];
                $j++;
            }else{
                break;
            }
           
        }while($j<$min);

        return $p;
    }