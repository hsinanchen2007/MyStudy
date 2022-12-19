### 解题思路
先统计两数组中数量，根据对比统计结果，将$key相同的元素写进$nums3，出现次数通过统计结果选择少的$value

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $nums1s = array_count_values($nums1);
        $nums2s =array_count_values($nums2);
        $nums3 = array();
        foreach ($nums1s as $key1 => $value1) {
            foreach ($nums2s as $key2 => $value2) {
                if($key1 == $key2){
                    if ($value1 > $value2) {
                        for ($i = 0; $i < $value2; $i++) {
                            array_push($nums3, $key1);
                        }
                    }else{
                        for ($j = 0; $j < $value1; $j++) {
                            array_push($nums3, $key1);
                        }
                    }
                }
            }
        }
        return $nums3;
    }
}
```