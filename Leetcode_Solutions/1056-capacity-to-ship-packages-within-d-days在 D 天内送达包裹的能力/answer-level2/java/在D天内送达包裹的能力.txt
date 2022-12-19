### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int lo=0, hi=0;
        for(int i=0;i<weights.length;i++)
            hi+=weights[i];
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if(canShip(weights,D,mid))
                hi=mid;
            else
                lo=mid+1;
        }
        return lo;
    }

    public boolean canShip(int [] weights,int D,int K){
        int cur=K;   //cur表示当前船只的可用承载量
        for(int weight:weights)
        {
            if(weight>K)
                return false;
            if(cur<weight){
                cur=K;
                D--;
            }    
            cur-=weight;
        }
        return D>0 ;
    }
}
```