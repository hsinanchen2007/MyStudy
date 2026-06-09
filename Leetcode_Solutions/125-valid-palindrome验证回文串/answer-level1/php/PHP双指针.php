- 过滤杂项
- 时间复杂度O(n)
- 空间复杂度O(1)
```
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isPalindrome($s) {
        if (empty($s)) return true;
        $str = $rStr = "";
        $count = strlen($s);
        $l = 0;
        $r = $count - 1;
        while ($l < $r) {
            $lLeter = $this->letter($s[$l]);
            $rLeter = $this->letter($s[$r]);
            if ($lLeter===false) {
                $l++;
                continue;
            }
            if ($rLeter===false) {
                $r--;
                continue;
            }
            if ($lLeter != $rLeter) {
                return false;
            }
            $l++;$r--;
        }
        return true;
    }
    
    function letter($str) {
        if ($str >= 'a' && $str <= 'z') {
            return $str;
        } elseif ($str >= 'A' && $str <= 'Z') {
            return chr(ord($str) + 32);
        } elseif (in_array($str,['0','1','2','3','4','5','6','7','8','9'])) {
            return $str;
        }
        return false;
    }
}
```
