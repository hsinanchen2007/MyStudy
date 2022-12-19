### 解题思路
重复计算 前两天 跟今天的最大和

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function massage($nums) {
        $size = count($nums);
        if ($nums == null || $size == 0)
			return 0;
		if ($size == 1)
			return $nums[0];
		
        $day_one_max = $nums[0];
		$day_two_max = max($day_one_max, $nums[1]);
        
        //start from the 3rd number
		for ($i = 2; $i < $size; $i++) {
			$day_before_today_max = $day_one_max;
			$day_one_max = $day_two_max;
			$day_two_max = max($day_two_max, $day_before_today_max + $nums[$i]);
		}
		return $day_two_max;
    }
}
```