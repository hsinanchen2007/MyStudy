```
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
    	$len = strlen($s);
    	// 把每个单词都放到数组里面
    	$words = [];
    	$str = '';
    	for ($i=0; $i < $len; $i++) { 
    		if ($s[$i] === ' ') {
    			if ($str) {
    				$words[] = $str;
    			}
    			$str = '';
    			continue;
    		} else {
    			$str .= $s[$i];
    		}
    	}

    	if ($str) {
    		$words[] = $str;
    	}
    	$wordCount = count($words);
    	$string = '';
    	for ($j=$wordCount - 1; $j >= 0; $j--) { 
    		$string .= $words[$j];
    		if ($j > 0) {
    			$string .= ' ';
    		}
    	}
    	return $string;
    }
}

```