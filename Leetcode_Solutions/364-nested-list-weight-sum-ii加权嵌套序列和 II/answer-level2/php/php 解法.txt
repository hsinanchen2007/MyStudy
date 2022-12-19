```
class Solution {

    /**
     * @param NestedInteger[] $nestedList
     * @return Integer
     */
    function depthSumInverse($nestedList) {
        $depth = $this->getDepth($nestedList);
        return $this->dfs($nestedList, $depth);
    }

    function getDepth($nestedList){
        $depth = 0;
        foreach($nestedList as $one){
            $depth = max($depth,$this->getDepth($one->getList())+1);
        }
        return $depth;
    }

    function dfs($nestedList, $depth){
        $sum = 0;
        foreach($nestedList as $one){
            if($one->isInteger()){
                $sum += $one->getInteger() * $depth;
            }else{
                $sum += $this->dfs($one->getList(), $depth-1);
            }
        }
        return $sum;
    }
}
```
