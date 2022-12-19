- 建立新字符串
- 反转填入
- 时间复杂度O(n)
- 空间复杂度O(n)
```PHP []
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function reverseOnlyLetters($S) {
        $out = $str = '';
        $count = strlen($S);
        for ($i=$count - 1;$i>=0;$i--) {
            if ($this->isLetter($S[$i])) {
                $str .= $S[$i];   
            }
        }
        for ($i=0,$j=0;$i<$count;$i++) {
            if ($this->isLetter($S[$i])) {
                $out .= $str[$j];
                $j++;
            } else {
                $out .= $S[$i];
            }
            
        }
        return $out;
    }
    
    function isLetter($str){
        $out = false;
        if (($str >= 'a' && $str <= 'z') || ($str >= 'A' && $str <= 'Z')) {
            $out = true;
        } 
        return $out;
    }
}
```
```GO []
func reverseOnlyLetters(S string) string {
    var str,out string
    for i:=len(S)-1;i>=0;i--{
        if isLetter(S[i]) {
            str += string(S[i])
        }
    }
    
    for i,j:=0,0;i<len(S);i++ {
        if isLetter(S[i]) {
            out += string(str[j])
            j++
        } else {
            out += string(S[i])
        }
    }
    
    return out
}

func isLetter (str byte) bool{
    var out bool
    if (str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z') {
        out = true
    }
    return out
}
```