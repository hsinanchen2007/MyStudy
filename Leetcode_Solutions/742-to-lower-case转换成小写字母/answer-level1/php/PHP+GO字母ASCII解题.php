- `A` 到 `a` 的ASCII 相差32
```PHP []
class Solution {

    /**
     * @param String $str
     * @return String
     */
    function toLowerCase($str) {        
        $count = strlen($str);
        $out = '';
        for ($i=0;$i<$count;$i++) {
            $ascii = ord($str[$i]);
            if ($ascii >= 65 && $ascii <= 90) {
                $out .= chr($ascii + 32);
            } else {
                $out .= $str[$i];
            }
        }
        return $out;
    }
}
```
```GO []
func toLowerCase(str string) string {
    out := ""
    for _,val := range(str) {
        if val >= 65 && val <= 90{
            val += 32
        }
        out += string(val)
    }
    return out
}
```
