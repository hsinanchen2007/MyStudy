其实呢，题目很简单，我们只需要看奇数和偶数谁的个数少就行，因为同属于一种类型的数字(奇数或偶数)，都不会耗费体力，则题目如下若是
```
class Solution {
    public int minCostToMoveChips(int[] chips) {
        int evenNum = 0;
        int oddNum = 0;
        for(int i = 0; i < chips.length; i++){
            if((chips[i] % 2) == 0){
                evenNum ++;
            }else{
                oddNum ++;
            }
        }
        return evenNum > oddNum ?oddNum:evenNum;
    }    
}
```


