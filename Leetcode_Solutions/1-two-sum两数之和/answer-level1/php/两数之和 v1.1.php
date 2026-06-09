### 解题思路
为了优化 array_search 函数，把数组键值反转，其中遇到值重复反转后丢失的问题，用数组差比较保存到另一个数组中，这样带来内存使用大的情况，希望能继续优化。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $unique = array_unique($nums);
        $diff = array_flip(array_diff_assoc($nums,$unique));
        $unique = array_flip($unique);
        foreach($unique as $key=>$val){
            unset($unique[$key]);
            $mission = $target - $key;
            if(array_key_exists($mission,$unique)){
                return [$val,$unique[$target - $key]];
            };
            if(array_key_exists($mission,$diff)){
                return [$val,$diff[$target - $key]];
            };
        }
    }
}
```