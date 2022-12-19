1.第一次循环martix,找出0所在的行,标记0所在列的key值,并将该行全部赋值为0.
2.第二次循环tempArr,根据标记列的key值进行赋0.

```
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function setZeroes(&$matrix) {
        $save = [];
        $tempArr = $matrix;
        foreach($matrix as $key => $value) {
            $temp = array_search(0, $value);
            if ($temp !== false) {
                foreach($tempArr[$key] as $k => &$v) {
                    if ($v == 0) {
                        $save[] = $k;
                    }
                    $v = 0;
                }
            }
        }
        
        foreach($tempArr as $key => &$value) {
            foreach($value as $k => &$v) {
                if (in_array($k, $save)) {
                    $v = 0;
                }
            }
        }

        $matrix = $tempArr;

        return $matrix;
    }
}
```
