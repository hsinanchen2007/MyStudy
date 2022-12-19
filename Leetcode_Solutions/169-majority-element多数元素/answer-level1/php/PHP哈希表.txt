- 建立哈希表并统计
- 求n/2
- 遍历哈希表输出
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $count = count($nums);
        $mid = $count / 2;
        $hash = [];
        for ($i=0;$i<$count;$i++) {
            if (!isset($hash[$nums[$i]])) {
                $hash[$nums[$i]] = 1;
            } else {
                $hash[$nums[$i]] += 1;
            }
        }
        foreach ($hash as $key=>$value) {
            if ($value > $mid) {
                return $key;
            }
        }
        return false;
    }
}
```
