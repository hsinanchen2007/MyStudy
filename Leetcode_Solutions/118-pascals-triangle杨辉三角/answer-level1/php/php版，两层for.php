找了找规律。

```
class Solution {

    /**
     * @param Integer $numRows
     * @return Integer[][]
     */
    function generate($numRows) {
        if(!$numRows) {
            return [];
        }
    	$arr = [
    		[1]
    	];
        for ($i=2; $i <= $numRows; $i++) { 
        	$temp = [];
        	for ($j=0; $j < $i; $j++) { 
        		if (isset($arr[$i-2][$j-1]) && isset($arr[$i-2][$j])) {
        			$temp[] = $arr[$i-2][$j-1] + $arr[$i-2][$j];
        		} else {
        			$temp[] = 1;
        		}
        	}
        	$arr[] = $temp;
        }
        return $arr;
    }
}
```