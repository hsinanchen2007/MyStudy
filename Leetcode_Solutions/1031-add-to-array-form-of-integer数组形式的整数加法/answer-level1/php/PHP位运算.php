根据大佬思想,php实现
```
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer $K
     * @return Integer[]
     */
    function addToArrayForm($A, $K) {
        $count = count($A);
        $int = $K;
        $res = [];
        while (--$count >= 0 || $int > 0) {
            if ($count >= 0) {
                $int += $A[$count];
            }
            $res[] = $int % 10;
            $int /= 10;
        }
        krsort($res);
        if (count($res)!=1) {
            foreach($res as $key=>$value){
                if ($value != 0) {
                    break;
                }
                unset($res[$key]);
            }
        }
        return $res;
    }
}
```
