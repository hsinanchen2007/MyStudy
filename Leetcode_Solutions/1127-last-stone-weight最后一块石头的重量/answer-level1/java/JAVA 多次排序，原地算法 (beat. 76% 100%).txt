每次排序，取最大相减即可。
原地算法，空间复杂度O(1);时间复杂度较高

```
class Solution {
    public int lastStoneWeight(int[] stones) {   
        int length = stones.length;
        
        if(length == 2){return (Math.abs(stones[1]-stones[0]));}
        else if(length == 1){return stones[0];}
        else if(length == 0){return 0;}
        else
        {
            
            for(int i = length-1; i>0; i--)
            {
                Arrays.sort(stones);
                stones[length-1] -= stones[length-2];
                stones[length-2] = 0;
            } 
        }
            return stones[length-1];
        
    }
}
```
