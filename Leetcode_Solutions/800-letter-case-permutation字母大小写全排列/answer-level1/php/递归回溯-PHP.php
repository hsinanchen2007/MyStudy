好像没什么人用PHP，那就留点东西吧(逃
![image.png](https://pic.leetcode-cn.com/bbd7e293ce402cef0e4a7d146a10e258b7f5a340fc3d5f02df031329908fbf7b-image.png)

```
class Solution {
    public $arr = [];
    function letterCasePermutation($S) {
        $this->helper($S,0,"",strlen($S));
        return $this->arr;
    }

    function helper($S,$i,$tmp,$l){
        for($j = $i;$j < $l;$j++){
            if(is_numeric($S[$j])){
                $tmp .= $S[$j];
            }else{
                if(strtolower($S[$j]) == $S[$j]){
                    // up
                    $this->helper($S,$j+1,$tmp.strtoupper($S[$j]),$l);
                }else{
                    // low
                    $this->helper($S,$j+1,$tmp.strtolower($S[$j]),$l);
                }
                $tmp .= $S[$j];
            }
        }
        if(strlen($tmp) == $l){
            $this->arr[] = $tmp;
        }
    }
}
```
