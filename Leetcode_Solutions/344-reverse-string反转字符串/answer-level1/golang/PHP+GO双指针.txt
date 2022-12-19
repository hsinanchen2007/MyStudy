可能写的比较啰嗦,但是很清晰
```PHP []
class Solution {

    /**
     * @param String[] $s
     * @return NULL
     */
    function reverseString(&$s) {
        $l = 0;
        $r = count($s) - 1;
        while($l < $r){
            $temp = $s[$l];
            $s[$l] = $s[$r];
            $s[$r] = $temp;
            $l++;
            $r--;
        }        
    }
}
```
```GO []
func reverseString(s []byte)  {
    l := 0
    r := len(s) - 1
    for l < r {
        s[l], s[r] = s[r], s[l]
        l++
        r--
    }
}
```