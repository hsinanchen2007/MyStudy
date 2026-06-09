1. 排序
2. 细节处理
3. 边界处理
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        if (empty($nums)) {
            return false;
        }
        sort($nums);
        $count = count($nums);
        if ($count==1) {
            return $nums[0] == 0 ? 1 : 0;
        }
        $times = 0;
        for ($i=0;$i<$count;$i++) {
            if ($nums[$i] != $times) {
                return $times;
            }
            $times++;
        }
        return $times;
    }
}
```
