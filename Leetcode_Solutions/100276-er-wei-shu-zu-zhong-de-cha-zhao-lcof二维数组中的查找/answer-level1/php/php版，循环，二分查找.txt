
以下的代码，其实一看题目就有的。

细想下，一个数会落在这个多维数组的其中一组。可根据末尾元素去找组，然后定位到之后。再细找这个组的。
```
class Solution {

    /**
     * @param Integer[][] $matrix
     * @param Integer $target
     * @return Boolean
     */
    function findNumberIn2DArray($matrix, $target) {
        $count = count($matrix);
        if(!$count) {
            return false;
        }
        for($i = 0; $i <= $count; $i++) {
            if($this->binarySearch($matrix[$i], $target)) {
                return true;
            }
        }
        return false;
    }

    function binarySearch($arr, $target) {
        $l = 0;
        $r = count($arr) - 1;
        while($l <= $r) {
            $mid = floor(($l + $r)/ 2);
            if($arr[$mid] < $target) {
                $l = $mid + 1;
            }elseif($arr[$mid] > $target) {
                $r = $mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
}

```