```
class ValidWordAbbr {
    /**
     * @param String[] $dictionary
     */
    function __construct($dictionary) {
        $this->map = [];
        foreach($dictionary as $s){
            $this->map[$this->toAbbr($s)][$s] = 1;
        }
    }
  
    /**
     * @param String $word
     * @return Boolean
     */
    function isUnique($word) {
        $index = $this->toAbbr($word);
        if(!isset($this->map[$index])) return true;
        if(count($this->map[$index])==1 && $this->map[$index][$word]==1) return true;
        return false;
    }

    function toAbbr($s){
        $n = strlen($s);
        if($n<=2) return $s;
        return $s[0].($n-2).$s[$n-1];
    }
}
```
