### 解题思路
打表，记录已经出现的数字

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findRepeatNumber($nums) {

        // 打表法
        $map = [];
        $count = count($nums);

        for($i = 0; $i < $count; $i++) {
            
            if(isset($map[$nums[$i]])) {
                // 表里面有的，证明出现过了，就输出一个就好
                return $nums[$i];
            } else {
                // 没有就记录进表
                $map[$nums[$i]] = true;
            }
        }
    }
}
```