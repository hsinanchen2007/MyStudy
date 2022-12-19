```
class Solution {

    /**
     * @param String[] $s
     * @return NULL
     */
    function reverseWords(&$s) {
        $i = 0;
        $j = count($s) - 1;
        $this->reverse($s,$i,$j); // 整个数组翻转
        for($j=0;$j<count($s);$j++){ // 单个词翻转
            if($s[$j] === " "){
                $this->reverse($s,$i,$j-1);
                $i = $j+1;
            }
            if($j === count($s) - 1){
                $this->reverse($s,$i,$j);
            }
        }
    }

    function reverse(&$s,$i,$j){
        while($i<$j){
            $this->swap($s,$i,$j);
            $i++;
            $j--;
        }
    }

    function swap(&$s,$i,$j){
        $tmp = $s[$i];
        $s[$i] = $s[$j];
        $s[$j] = $tmp;
    }
}
```
