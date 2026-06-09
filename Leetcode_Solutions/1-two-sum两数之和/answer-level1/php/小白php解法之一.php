![image.png](https://pic.leetcode-cn.com/8b9bba58fb6cb04bfe3d561e6eb75ad65dcf6c348a61c156114d6f1d0b8e3cd1-image.png)

```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
     $counts = count($nums);
		$diff_arr = array();
			for ($i = 0;$i<=$counts;$i++) {
				$val = $target - $nums[$i];
				unset($nums[$i]);
				if(in_array($val,$nums)){
					return array($i,array_search($val, $nums));
				}
			}
		
    }
}
```
