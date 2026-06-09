直接上代码
```
class Solution {

    /**
     * @param Integer[][] $costs
     * @return Integer
     */
    function twoCitySchedCost($costs) {
        
        $n = count($costs)/2;
        $result = 0;
        
        //先对数组进行差值排序
        usort($costs , function($a, $b){
            if (($a[0]-$a[1])==($b[0]-$b[1])) return 0;
            return (($a[0]-$a[1])<($b[0]-$b[1]))?-1:1; 
        });
        
        //直接累加
        foreach ($costs as $k => $v){
            if($k < $n){
                $result += $v[0];
            }else{
                $result += $v[1];
            }
            
        }
        
        return $result;
        
    }

}
```