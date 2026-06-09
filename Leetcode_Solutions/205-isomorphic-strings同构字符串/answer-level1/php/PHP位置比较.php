评论区大佬思路确实巧妙.膜拜一下.哈希表互相映射也可以解决问题
```
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isIsomorphic($s, $t) {
        $counts = strlen($s);
        for ($i=0;$i<$counts;$i++) {
            if (strpos($t, $t[$i]) != strpos($s, $s[$i])) {
                return false;
            }
        }
        return true;
    }
}
```
