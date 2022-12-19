![image.png](https://pic.leetcode-cn.com/6c7c058f4583d3c1d40785bc365f5047237cf91b4674921d223c229fb6c27948-image.png)


```
class Solution {
    public int lastStoneWeight(int[] stones) {
        if (stones.length == 1)return stones[0];
        
        for (int i = stones.length-1; i >= 0; i--){
            Arrays.sort(stones);
            stones[stones.length - 1] = Math.abs(stones[stones.length - 1] - stones[stones.length - 2]);
            stones[stones.length - 2] = 0;
            
        }

        return stones[stones.length - 1];
    }
}
```
