```
class Solution {

    private $ch = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];

    function reverseVowels($s) {
        $left = 0;
        $right = strlen($s)-1;
        while($left < $right){
            while(isset($s[$left]) && !in_array($s[$left],$this->ch)) $left++;
            while(isset($s[$right]) && !in_array($s[$right],$this->ch)) $right--;
            if($left >= $right) break;
            $this->swap($s,$left,$right);
            $left++;
            $right--;
        }
        return $s;
    }
    
    function swap(&$ch,$i,$j){
        $tmp = $ch[$i];
        $ch[$i] = $ch[$j];
        $ch[$j] = $tmp;
    }
}
```
