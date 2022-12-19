### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n<2){
            return 0;
        }
        if(n ==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        int[] res= new int[n+1];
        res[1] =1;
        res[2]=2;
        res[3]=3;
        int max =0;
        for(int i=4; i<=n; i++){
            max =0;
            for(int j=1; j<=i/2; j++){
                max = Math.max(max, res[j] * res[i-j]);
                res[i]= max;
            }
            
        }
        return res[n];
    }
}
```