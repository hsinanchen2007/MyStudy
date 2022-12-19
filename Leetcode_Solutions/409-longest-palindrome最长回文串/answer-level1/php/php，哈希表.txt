我思路是有的。但有个细节没想到。参考了下网友的解。
```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $len = strlen($s);
        $hashMap = [];
        for ($i=0; $i < $len; $i++) { 
        	$hashMap[$s[$i]] = ($hashMap[$s[$i]] ?? 0)+1; 
        }
       	if (count($hashMap) == 1) {
       		return current($hashMap);
       	}
        $count = 0;
        $flag = 0;
        foreach ($hashMap as $k => $v) {
        	if ($v % 2 == 0) {
        		$count += $v;
        	} elseif (($v - 1) % 2 == 0) {
        		$count += $v - 1;
        		$flag = 1;
        	}  
        }

        
        return $count + $flag;
    }
}
```