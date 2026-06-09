# 方法一 双指针
```PHP []
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        if ($x < 0) return false;
        if ($x == 0) return true;
        $str = (string)$x;
        
        $l = 0;
        $r = strlen($str) - 1;
        
        while ($l < $r) {
            if ($str[$l] != $str[$r]) {
                return false;
            }
            $l++;$r--;
        }
        return true;
    }
}
```
```GO []
func isPalindrome(x int) bool {
    if x < 0 {return false}
    if x == 0 {return true}
    
    str := strconv.Itoa(x)
    l,r := 0, len(str)-1
    
    for l < r {
        if str[l] != str[r] {return false}
        l++
        r--
    }
    return true
}
```
# 方法二 反转
```PHP数学 []
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        if ($x < 0) return false;
        if ($x == 0) return true;
        $integer = 0;
        $target = $x;
        while($target>=1){
            $bit = $target % 10;
            $target /= 10;
            $integer = $integer * 10 + $bit;
        }
        return $integer==$x;
    }
}
```
```PHP字符串 []
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        if ($x < 0) return false;
        if ($x == 0) return true;
        $str = (string)$x;

        $integer = '';
        for ($i=strlen($x)-1;$i>=0;$i--) {
            $integer .= $str[$i];
        }
        return $integer==$str;
    }
}
```
