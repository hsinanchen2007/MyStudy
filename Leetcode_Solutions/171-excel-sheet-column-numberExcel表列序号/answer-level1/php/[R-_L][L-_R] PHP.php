```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function titleToNumber($s) {
        //Time: O(n), Space: O(1)
        return $this->titleToNumberR2L($s);
        // Time: O(n), Space: O(1)
        return $this->titleToNumberL2R($s);
    }

    //从低位到高位《从26进制最低位开始处理，维护每一位一个base》
    function titleToNumberR2L($s) {
        $base = 1;
        $num = 0;
        //ABC = C * 1 + B * 26 + A * 676
        for ($i = strlen($s) - 1; $i >= 0; --$i) {
            $num += (ord($s[$i]) - 64) * $base;
            $base *= 26;
        }
        return $num;
    }

    //从高位到低位
    function titleToNumberL2R($s) {
        $num = 0;
        //ABC = (A * 26 + B) * 26 + C
        for ($i = 0; $i < strlen($s); ++$i) {
            $num = $num * 26 + (ord($s[$i]) - 64);
        }
        return $num;
    }
}
```
