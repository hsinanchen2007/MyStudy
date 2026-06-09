array_count_values()函数统计

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $half = count($nums) / 2;
        $arrayCount = array_count_values($nums);

        foreach ($arrayCount as $key => $val) {
            if ($val > $half) {
                return $key;
            }
        }

        return 0;
    }
}
```