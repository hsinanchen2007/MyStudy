```
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function compressString($S) {
        $sLen = strlen($S);	
        if ($sLen <3) {
        	 return $S;
        }

        $letter = $S[0];
        $count = 1;
        $c = '';
        for ($i=1; $i < $sLen; $i++) { 
        	if ($letter === $S[$i]) {
        		$count++;
        	} else {
        		$c .= $letter.$count;
        		$count = 1;
        		$letter = $S[$i];
        	}
        }
        $c .= $letter.$count;
        return strlen($c) < $sLen ? $c : $S;
    }
}

```