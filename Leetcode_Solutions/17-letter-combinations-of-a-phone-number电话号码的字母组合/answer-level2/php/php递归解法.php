```
class Solution {
    private $phone = array(
                          1=>null,
                          2=>array('a','b','c'),
                          3=>array('d','e','f'),
                          4=>array('g','h','i'),
                          5=>array('j','k','l'),
                          6=>array('m','n','o'),
                          7=>array('p','q','r','s'),
                          8=>array('t','u','v'),
                          9=>array('w','x','y','z'),
                        );
    /**
     * @param String $digits
     * @return String[]
     */
    function letterCombinations($digits) {
        if(empty($digits)) return array();
        if(strlen($digits)==1) return $this->phone[$digits];
        $cond = $this->phone[$digits[0]];
        $res = $this->back($cond,substr($digits,1));
        return $res;
    }
    
    function back($cond,$str){
		$parr = $this->phone[$str[0]];
		$ans = array();
        for($i=0;$i<count($cond);$i++){
            for($j=0;$j<count($parr);$j++){
                $ans[] = $cond[$i].$parr[$j];
            }
        }
		if(strlen($str)==1){
			return $ans;
		}
        return $this->back($ans,substr($str,1));
    }
}
```
