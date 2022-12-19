### 解题思路
1. 对数组从小到大排序
2. 循环判断上当前值与上一次的值是否相同
3. 相同删除并且不记录当前值
4. 不相同记录当前值

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $count = count($nums);
        if ( $count < 1 ) {
            return $count;
        }
        sort($nums);
        $last_num = $nums[0];
        for ( $i = 1; $i < $count; $i++ ) {
            if ( $nums[$i] == $last_num ) {
                unset($nums[$i]);
                continue;
            }
            $last_num = $nums[$i];
        }
    }
}
```