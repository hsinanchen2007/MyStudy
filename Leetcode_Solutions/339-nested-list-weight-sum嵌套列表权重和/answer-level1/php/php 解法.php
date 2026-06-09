```
class Solution {

    /**
     * @param NestedInteger[] $nestedList
     * @return Integer
     */
    function depthSum($nestedList) {
        return $this->dfs($nestedList, 1);
    }

    function dfs($nestedList, $depth){
        $sum = 0;
        foreach($nestedList as $one){
            if($one->isInteger()){
                $sum += $one->getInteger() * $depth;
            }else{
                $sum += $this->dfs($one->getList(), $depth+1);
            }
        }
        return $sum;
    }
}
```
