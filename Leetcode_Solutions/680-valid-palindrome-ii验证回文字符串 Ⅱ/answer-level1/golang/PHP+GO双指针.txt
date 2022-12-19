- 遍历字符串,遇到不相等的字符,左侧指针+1判断 || 右侧指针-1判断
- 时间复杂度O(n)
- 空间复杂度O(1)
```PHP []
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function validPalindrome($s) {
        $count = strlen($s);        
        for ($i=0,$r=$count - 1;$i<$count;$i++,$r--) {
            if ($s[$i] != $s[$r]) {
                return $this->isBool($s,$i+1,$r) || $this->isBool($s,$i,$r-1); 
            }
        }
        return true;
    }
    
    function isBool ($s, $l, $r) {
        var_dump($s, $l, $r);
        while ($l < $r) {
            if ($s[$l] != $s[$r]) {
                return false;
            }
            $l++;$r--;
        }
        return true;
    }
}
```
```GO []
func validPalindrome(s string) bool {
    r := len(s) - 1
    for i:=0;i<len(s);i++ {
        if s[i] != s[r] {
            return isBool(s, i+1, r) || isBool(s, i, r-1)
        }
        r--
    }
    return true
}

func isBool (s string, l int, r int) bool {
    for l < r {
        if s[l] != s[r] {
            return false;
        }
        l++
        r--
    }
    return true
}
```
