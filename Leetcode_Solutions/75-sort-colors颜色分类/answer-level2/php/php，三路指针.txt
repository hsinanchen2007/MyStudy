最容易想到的肯定是计数排序。用一个hash表搞定。


题解：参考《玩转算法面试 从真题到思维全面提升算法思维》3-5节

三路快排也是一样的思想。

多指针的，定义好边界就ok。
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function sortColors(&$nums) {
    	//  [ ..   .]
    	// $zero $i $two; 三路
    	$zero = -1;
    	$two = count($nums);
    	for ($i=0; $i < $two;  ) { 
    		if ($nums[$i] == 0) {
    			[$nums[$zero], $nums[$i]] = [$nums[$i], $nums[++$zero]];
    			$i++;
    		} elseif ($nums[$i] == 2) {
    			[$nums[$two], $nums[$i]] = [$nums[$i], $nums[--$two]];
    		} else {
    			$i++;
    		}
    	}
    }
}
```