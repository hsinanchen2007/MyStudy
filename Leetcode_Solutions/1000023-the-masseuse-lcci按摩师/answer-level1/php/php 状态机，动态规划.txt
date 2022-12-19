### 解题思路
一定要搞清楚状态转换

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function massage($nums) {
        $count = count($nums);
        if($count == 1){
            return $nums[0];
        }
        $dp_0 = 0;
        $dp_1 = $nums[0];
        for($i=1; $i<$count; $i++){
            // 没有预约则说明前一天有预约或者没有预约均可
            $dp_i_0 = max($dp_0, $dp_1);
            // 有预约则用说明前一天必然没有预约
            $dp_i_1 = $dp_0 + $nums[$i];

            $dp_0 = $dp_i_0;
            $dp_1 = $dp_i_1;
        }

        return max($dp_0, $dp_1);
    }

}
```