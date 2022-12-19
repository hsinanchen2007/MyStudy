![image.png](https://pic.leetcode-cn.com/1bc91c593541d93c621db610a8b1e895146b10d798f32aa789ee91980f31c915-image.png)
生成hash表后,再遍历hash表,空间复杂度O(1),时间复杂度O(2(m+n))
```
class Solution {

    /**
     * @param String $A
     * @param String $B
     * @return String[]
     */
    function uncommonFromSentences($A, $B) {
        $a = explode(' ', $A);
        $b = explode(' ', $B);
        $counta = empty($A) ? 0 : count($a);
        $countb = empty($B) ? 0 : count($b);

        $hash = [];
        for ($i=0;$i<$counta;$i++) {
            if ( !isset($hash[$a[$i]]) ) {
                $hash[$a[$i]] = 1;
            } else {
                $hash[$a[$i]] += 1;
            }
        }
        for ($i=0;$i<$countb;$i++) {
            if ( !isset($hash[$b[$i]]) ) {
                $hash[$b[$i]] = 1;
            } else {
                $hash[$b[$i]] += 1;
            }
        }

        $out = [];
        foreach ($hash as $key=>$value) {
            if ($value == 1) {
                $out[] = $key;
            }
        }
        return $out;
    }
}
```
