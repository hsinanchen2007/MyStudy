#### 题解1
从任意一个点开始，判断其是否能绕环路一周。

```java 
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int l = gas.length;
        for(int i =0;i<l;i++){
            int j = i;
            int carry = 0;
            int step=0;
            while(step<l){
                int mov = carry+gas[j]-cost[j];
                // System.out.println(i+" "+j+" "+mov);
                if(mov<0){
                    break;
                }
                carry = mov;
                j = (j+1)%l;
                step++;
            }
            if(step==l){
                return j;
            }
        }
        return -1;
        
    }
}
```

#### 题解2

仔细思考有以下结论：
* 如果cost和小于gas和，则一定不存在解
* 如果cost和大于等于gas和，则一定存在解

同时，经过思考我们还有以下结论：如果从i出发，j是第一个不可达的点，则i到j之间的任何一个点出发无法到达j，即i到j-1都不是答案。
```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int gs = 0;
        int cs = 0;
        int l = gas.length;
        for(int i =0 ;i<l;i++){
            gs += gas[i];
            cs += cost[i];
        }
        if(gs<cs){
            return -1;
        }
        int ans = 0;
        int carry = 0;
        for(int i =0;i<l;i++){
            carry = carry + gas[i]-cost[i];
            if(carry<0){
                ans = i+1;
                carry = 0;
            }
        }
        return ans;
    }
}
```