```

class Solution {

    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer[]
     */
    function getLeastNumbers($arr, $k) {
    	$heap = new SplMinHeap();
    	foreach ($arr as $key => $value) {
    		$heap->insert($value);
    	}

    	$result = [];
    	$count = 0;
    	foreach ($heap as  $value) {
    		if ($count < $k) {
    			$result[] = $value;
    		} else {
    			break;
    		}
    		$count++;
    	}
    	return $result;
    }
}

```