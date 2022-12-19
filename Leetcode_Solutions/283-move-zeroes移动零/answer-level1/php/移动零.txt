0,1,0,3,12

循环0和1进行交换
1,0,0,3,12
然后从第二个建值比对第三个建值都为0不进行造作，比对第四个建值不为0进行交换得到
1,3,0,0,12
以此类推
1,3,12,0,0
代码
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        
        $j = 1;
        $count = count($nums);
        for( $i = 0; $i<$count; $i++ ) {
            
            $y = $i;
            if ($nums[$i] == 0) {
                
                while(true) {
                    
                    $y = $y + 1;
                    if ($y==$count) {
                        break;
                    }
                    
                    if ( $nums[$y] != 0 ) {
                        
                        $nums[$i] = $nums[$y];
                        $nums[$y] = 0;
                        break;
                    }
                    
                }
                
            }
        }
        
        return $num;
        
    }
    
}
```


