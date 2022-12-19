本来是有思路了。但是写残了。 思路也只是近似。故参考了别人题解。

```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
    	$count  = count($nums);
    	if ($count < 3) {
    		return [];
    	}
       	sort($nums);
        
        $res = [];
        for ($i=0; $i < $count; $i++) { 
        	if ($nums[$i] > 0) {
        		return $res;
        	}
        	if ($i>0 && $nums[$i] == $nums[$i-1]) {
        		continue;
        	}
        	$l = $i+1;
        	$r = $count - 1 ;
        	while ($l < $r) {
        		$result = $nums[$l] + $nums[$i] + $nums[$r]; 
        		if ($result > 0) {
	        		$r--;
	        	} elseif ($result < 0) {
	        		$l++;
	        	} else {
	        		$res[] = [$nums[$l], $nums[$i], $nums[$r]];
	        		while ($l < $r && $nums[$l] == $nums[$l+1]) {
	        			$l++;
	        		}
	        		while ($l < $r && $nums[$r] == $nums[$r-1]) {
	        			$r--;
	        		}
	        		$l++;
	        		$r--;
	        	}
        	}
        }
        // while (($j-$i) > 1) {
        // 	for ($k=$i+1; $k < $j; $k++) {
        // 		$result = $nums[$i] + $nums[$j] + $nums[$k]; 
        // 		if ($result > 0) {
	       //  		// $j--;
	       //  	} elseif ($result < 0) {
	       //  		// $i++;
	       //  	} else {
	       //  		$a = [$nums[$i], $nums[$k], $nums[$j]];
	       //  		if (!in_array($a, $temp)) {
	       //  			$temp[] = [$nums[$i], $nums[$k], $nums[$j]];
	       //  		}
	        		
	       //  		// if($nums[$j] === $nums[$j-1]) {
	       //  		// 	$j--;
	       //  		// }
	       //  		// $j--;
	       //  	}
        // 	}

        // 	$i++;
        // 	$j--;
        // }


        return $res;
    }
}

```