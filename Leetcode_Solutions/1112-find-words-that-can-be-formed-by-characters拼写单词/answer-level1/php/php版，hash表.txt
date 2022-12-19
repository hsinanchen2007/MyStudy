```
class Solution {

    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $sLen = strlen($chars);
        $hashMap = [];
        for ($i=0; $i < $sLen; $i++) { 
        	$hashMap[$chars[$i]] = ($hashMap[$chars[$i]] ?? 0) +1;
        }

        $wCount = count($words);
        $count = 0;
        $tempHash = $hashMap;
        for ($j=0; $j < $wCount; $j++) { 
        	$str = $words[$j];
        	$sLen = strlen($str);
        	$flag = 1;
        	for ($k=0; $k < $sLen; $k++) { 
        		if (!isset($hashMap[$str[$k]]) || !$hashMap[$str[$k]]) {
        			$flag = 0;
        			continue;
        		} else {
        			$hashMap[$str[$k]]--;
        		}
        	}

        	if ($flag) {
        		$count += $sLen;
        	}
        	$hashMap = $tempHash;
        }

        return $count;
    }
}


```