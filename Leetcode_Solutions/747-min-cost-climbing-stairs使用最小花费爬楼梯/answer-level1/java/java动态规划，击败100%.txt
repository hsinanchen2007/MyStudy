![image.png](https://pic.leetcode-cn.com/905199beba37c1ace3b33ccb1c9fa8e161697a1477369199e4d46455ec4079a4-image.png)
![image.png](https://pic.leetcode-cn.com/814ede2e568716091c078485c2f34e49a5446cdb1daf83f5390cb93213d54f43-image.png)

```java []
class Solution {
    public final int minCostClimbingStairs(int[] cost) {
        int size=cost.length;
        if(cost==null||size==0){return 0;}
        int[] cache=new int[size];
        cache[size-1]=cost[size-1];
        cache[size-2]=cost[size-2];
        minCostClimbingStairs(cost,0,cache);
        return Math.min(cache[0],cache[1]);
    }
    
    public final void minCostClimbingStairs(int[] cost,int index,int[] cache){     
        int size=cost.length;
        for(int i=size-3;i>=index;i--){
            cache[i]=Math.min(cost[i]+cache[i+1],cost[i]+cache[i+2]);
        }
    }
    
}
```

