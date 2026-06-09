1. 建立哈希表并且计数
2. 查找哈希表,值大于1则减一,值为1则删除掉
3. 如果没有找到该字符,则返回当前字符
```
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return String
     */
    function findTheDifference($s, $t) {
        $hash = [];
        $tLen = strlen($t);
        $sLen = strlen($s);
        for ($i=0;$i<$sLen;$i++) {
            if (isset($hash[$s[$i]])) {
                $hash[$s[$i]] += 1;
            } else {
                $hash[$s[$i]] = 1;
            }
        }
        for ($i=0;$i<$tLen;$i++) {
            if (isset($hash[$t[$i]]) && $hash[$t[$i]] > 1) {
                $hash[$t[$i]] -= 1;
            } elseif (isset($hash[$t[$i]]) && $hash[$t[$i]] == 1) {
                unset($hash[$t[$i]]);
            } elseif (!isset($hash[$t[$i]])) {
                return $t[$i];
            }
        }
    }
}
```
