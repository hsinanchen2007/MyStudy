初学java

先计算没有X的情况下用户能得到的满意值

然后计算X能带来的满意值提升，每次加入一个"分钟"，然后去掉一个"分钟"，然后计算最大值


java击败99.66%

```
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int satisfy = 0;
        //计算没有X的情况下满意值
        for(int i=0; i<customers.length; i++){
            if(grumpy[i] == 0){
                satisfy += customers[i];
            }
        }
        
        int max_satisfy = 0;
        int current_satisfy = 0;
        
        //计算X能带来的满意值提升
        for(int i=0; i<X; i++){
            if(grumpy[i] == 1){
                current_satisfy += customers[i]; 
            }
        }
        
        max_satisfy = current_satisfy;
        
        for(int i=X; i<customers.length; i++){
            if(grumpy[i] == 1){
                current_satisfy += customers[i];
            }
            
            if(grumpy[i - X] == 1){
                current_satisfy -= customers[i - X];
            }
            
            max_satisfy = Math.max(current_satisfy, max_satisfy);
        }
        
        return max_satisfy + satisfy;
        
    }
}
```