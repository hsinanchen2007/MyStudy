```
class Solution {

    /**
     * @param Integer $n
     * @return String
     */
    function countAndSay($n) {
        $map[1]     = '1';
        //读前一个数
        for( $i = 2; $i <= $n; $i++ ) {
            $this->read( $map[$i-1], $i, $map );
        }
        
        return $map[$n];
    }
    
    //读方法
    function read( $str, $n, &$map )
    {
        $i      = 0;
        $ret    = '';
        $len    = strlen( $str );
        while( $i < $len ) {
            $tmp    = 1; //至少出现一次
            while( $i+1 < $len && $str[$i] == $str[$i+1]) {
                $tmp++;
                $i++;
            }
            $ret    .= "{$tmp}{$str[$i]}"; //累计字符串
            $i++;
        }
        
        $map[$n]    = $ret;
    }
}
```
