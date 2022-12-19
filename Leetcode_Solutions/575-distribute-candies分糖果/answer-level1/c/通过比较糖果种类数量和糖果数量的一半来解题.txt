先每种都喂妹妹吃一块，一边喂一边数吃了几块，如果吃了超过糖果总数的一半的数量就停手不喂了；如果每种都吃过了都还没到糖果总数一半，就随便喂点之前已经吃过的种类的糖果。
所以按照这个思路分类讨论一下，如果糖果种类≥糖果总数一半，则能吃到等于糖果总数一半的数量；如果糖果种数≤糖果总数一半，则能吃到所有种类的糖果，也就是能吃到等于糖果种数的数量。
```
public class Solution {
    public int DistributeCandies(int[] candies) {
        int max=1;
        Array.Sort(candies);
        for(int i=1;i<candies.Length;i++){
            if(candies[i]!=candies[i-1]){
                max++;
            }
        }
        if(max<candies.Length/2){return max;}
        return candies.Length/2;
    }
}
```

//顺便一提弟弟真可怜...或者说难道弟弟是不敢尝试新事物的人？
