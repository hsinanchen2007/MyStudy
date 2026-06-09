```PHP []
class Solution
{

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x)
    {
        $new_arr = array();
        if($x>0){
            $start=0;
            $sign='';
        }else{
            $start=1;
            $sign='-';
        }
        for ($i =$start ; $i < strlen($x); $i++) {
            $int=(int)substr($x, $i, 1);
                $new_arr[$i] = $int;
        }
        $new_arr=array_reverse($new_arr);
        $num=$sign.join('', $new_arr);
        $num = (int)$num;
        $max=pow(2,31)-1;
        $min=pow(-2,31);
        if($num>$max||$num<$min){
            return 0;
        }
        return $num;
    }
}
```