搜索当前元素上下左右位置并递归，若查到数据=1则计数并将该元素置为0，避免重复计数

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function maxAreaOfIsland($grid) {
    	$countX = count($grid[0]);
    	$countY = count($grid);
    	$max = 0;
    	for ($i=0; $i < $countY ; $i++) { 
    		for ($j=0; $j < $countX; $j++) { 
    			if(isset($grid[$i][$j]) && $grid[$i][$j] == 1) {
	                $res = $this->getIland($grid, $i, $j);
	                //var_dump($res);
	                $max = max($res, $max);
	            }
    		}
    	}
        return $max;
    }

    function getIland(&$grid, $i, $j) {
    	if (isset($grid[$i][$j]) && $grid[$i][$j] == 1) {
    		$grid[$i][$j] = 0;
    		$num = 1 + $this->getIland($grid, $i + 1, $j) + 
    		$this->getIland($grid, $i - 1, $j) +
    		$this->getIland($grid, $i, $j + 1) +
    		$this->getIland($grid, $i, $j - 1);
    		return $num;
    	}
    	return 0;
    }
}
```
