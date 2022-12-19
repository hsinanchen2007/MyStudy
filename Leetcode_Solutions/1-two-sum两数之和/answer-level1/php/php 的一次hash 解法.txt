先放结果：
![image.png](https://pic.leetcode-cn.com/81932bbc6b6e5d91a8666380d8896f3618221bc7adb51bc9daee5295a35e8ef9-image.png)

然后是代码：

解释上面 java  那里很详细了。
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum(array $nums, int $target) {
    	$v = 0;
    	$map = [];
    	$len = count($nums);
		for($i = 0; $i < $len; ++$i){
			$v = $target - $nums[$i];
		    if(array_key_exists($v, $map) && $i != $map[$v])
	        {
		        return [$map[$v] , $i];
		    }
			$map[$nums[$i]] = $i;
		}
    }
}
```