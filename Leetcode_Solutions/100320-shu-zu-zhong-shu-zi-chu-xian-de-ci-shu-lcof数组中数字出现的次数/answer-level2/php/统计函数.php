### 解题思路
php数组统计函数

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function singleNumbers($nums) {
        // $tempMap = [];
        // for ($i = 0; $count = count($nums), $i < $count; $i++) {
        //     if (isset($tempMap[$nums[$i]])) {
        //         unset($tempMap[$nums[$i]]);
        //     } else {
        //         $tempMap[$nums[$i]] = $nums[$i];
        //     }
        // }

        $tempMap = array_count_values($nums);
		$newTempMap = array_filter($tempMap, function($val) {
			if ($val == 1) {
				return true;
            }
		});

		return array_keys($newTempMap);
    }
}
```