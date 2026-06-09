
我的方法思路很简单，暂时没想到更简洁的思路。
就计算转向 跟 坐标i 跟坐标j 的变化情况。

```
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return Integer[]
     */
    function findDiagonalOrder($matrix) {    
        if(!$matrix ){
            return $matrix;
        }
        $list = [];
        foreach($matrix as $k => $v){
            if(is_array($v)){
                foreach($v as $K2 => $v2){
                    $list[] = $v2;
                }
            }else{
                $list[] = $v;
            }
        }
               
        
        $direction = 0;//方向，1代表右后转， 2代表左后转
        $change = false;//是否要转弯
        $isReverse = false;
        
        $m = count($matrix);//M行N列
        $n = count($matrix[0]);//N列
        $maxloop = max($m, $n);//最大循环次数
        //echo "m={$m},n={$n}";
        if($m==1 || $n==1){
            return $list;
        }
        
        $i = $j = 0;
        $newList = [];
        while(true){
            
            //$newList[] = $matrix[$i][$j];//存入元素
            $newList[] = $list[$i*$n + $j];//存入元素
            
            //echo "{$i}_{$j}=='.($i*$n + $j).'=={$matrix[$i][$j]}####";
            if($i==$m-1 && $j==$n-1 ){
                break;
            }
            
            if( ($direction==1&&$j>0&&$i<$m-1) || ($direction==2&&$i>0&&$j<$n-1)   ){//符合继续当前方向的取值
                if($direction==1){
                    $i += 1;
                    $j -= 1;
                }elseif($direction==2){
                    $i -= 1;
                    $j += 1;
                }    
            }else{
                $direction = $direction==1 ? 2 : 1;
                $change = true;
                $isReverse = false;
                if( ($direction==2&&($j==$n-1||$i==$m-1) ) || ($direction==1&& ($i==$m-1||$j==$n-1))  ){//倒置
                    //echo "反转";
                    $isReverse = ture;
                }
                
                if( ($direction==1&&!$isReverse) || ($direction==2&&$isReverse) ){//右后转时，坐标[$i, $j+1]，倒时[$i+1, $j]
                    //echo "come1";
                    $j = $j+1;
                }
                if( ($direction==2&&!$isReverse) || ($direction==1&&$isReverse) ){//左后转时，坐标[$i+1, $j], 倒时[$i, $j+1]
                    //echo "come2";
                    $i = $i+1;
                }
                
                //echo "direction=={$direction},isReverse==".(int)$isReverse.",jisuan=i={$i},j={$j}\r\n";
                
            }
        }
        return $newList;
    }
}




```
