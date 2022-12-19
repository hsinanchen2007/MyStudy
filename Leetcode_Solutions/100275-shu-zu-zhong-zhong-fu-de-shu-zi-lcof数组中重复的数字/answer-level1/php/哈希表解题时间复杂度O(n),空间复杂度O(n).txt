### 解题思路
1. 构建hash表,标记数字
2. 在hash表中查询是否存在,存在即返回该重复数字

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findRepeatNumber($nums) {
        $hash = [];
        $count = count($nums);
        for ($i=0;$i<$count;$i++) {
            if (isset($hash[$nums[$i]])) {
                return $nums[$i];
            } else {
                $hash[$nums[$i]] = true;
            }
        }
    }
}
```