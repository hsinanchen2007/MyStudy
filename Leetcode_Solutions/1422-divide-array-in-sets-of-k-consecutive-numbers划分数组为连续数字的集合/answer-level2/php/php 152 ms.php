```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Boolean
     */
    function isPossibleDivide($nums, $k) {
        if (count($nums) % $k != 0) {
            return false;
        }
        $countvalue = array_count_values($nums);
        ksort($countvalue);
        
        $isStop = false;
        $return = true;
        while ($isStop == false) {
            $key = key($countvalue);
            $value = current($countvalue);
            for ($i = 0; $i < $k; $i++) {
                if (array_key_exists($key + $i, $countvalue) && $countvalue[$key + $i] >= $value) {
                    $countvalue[$key + $i] -= $value;
                    if ($countvalue[$key + $i] == 0) {
                        unset($countvalue[$key + $i]);
                    }
                } else {
                    $return = false;
                    $isStop = true;
                    break;
                }
            }
            if (count($countvalue) == 0) {
                $return = true;
                $isStop = true;
            }
        }
        return $return;
    }
}
```
首先统计数组中所有的值，然后对值进行排序得到新的统计数组，while循环遍历统计数组，判断i到i+k之间的整数是否连续，如果连续，unset数组中的[i+k]元素，一旦遇到不连续返回false，否则继续while直到统计数组中元素为0