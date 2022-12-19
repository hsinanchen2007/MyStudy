![image.png](https://pic.leetcode-cn.com/3c468d46c6baf0618eb2f15067c262076f6742cd92a52902b3cf3edf7a67b6bd-image.png)
1. 建立hash
2. 标记对应的下标值
3. 判断重复的值是否小于等于`k`
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Boolean
     */
    function containsNearbyDuplicate($nums, $k) {
        $count = count($nums); // 总数
        $hash = []; // hash
        for ($i=0; $i<$count; $i++) {
            /**
             * 重复 则判断存储的值与当前`i`的差是否小于等于`k` 返回true
             */
            if (isset($hash[$nums[$i]]) && ($i - $hash[$nums[$i]]) <= $k) {
                return true;
            }
            # 建立hash table并且存储当前自己的位置,自己的位置用于碰到重复时进行判断
            $hash[$nums[$i]] = $i;
        }
        return false;
    }
}
```
