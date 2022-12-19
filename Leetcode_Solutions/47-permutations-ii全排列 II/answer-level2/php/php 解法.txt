本题相对46题只需要多一个判断剪枝的过程
ps: 好好理解!$used[$i-1] 这个判断,通过画递归流程图顺序理解会比较直观
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permuteUnique($nums) {
        $allList = [];
        sort($nums);
        $this->backtrack($nums,0,[],$allList,[]);
        return $allList;
    }
    
    function backtrack($nums,$depth,$stack,&$allList,$used){
        if($depth==count($nums)){
            $allList[] = $stack;
        }else{
            for($i=0;$i<count($nums);$i++){
                if(1==$used[$i]) continue;
                if($i>0 && $nums[$i]==$nums[$i-1] && !$used[$i-1]){
                    continue;
                }
                $used[$i] = 1;
                array_push($stack,$nums[$i]);
                $this->backtrack($nums,$depth+1,$stack,$allList,$used);
                $used[$i] = 0;
                array_pop($stack);
            }
        }
    }
}
```
