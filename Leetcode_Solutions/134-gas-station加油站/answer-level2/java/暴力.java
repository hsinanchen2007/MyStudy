
### 代码

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int gas_sum = 0;
        int count = 0;
        int k = Integer.MAX_VALUE;
        for(int i = 0 ; i < gas.length ; i++){
            for(int j = 0 ; j < gas.length ; j++){
                gas_sum += i + j < gas.length ? gas[i + j] : gas[i + j - gas.length];
                if(gas_sum <  (i + j < gas.length ?cost[i+j] : cost[i+j-gas.length]) ){
                    break;
                }
                else if(gas_sum >= (i + j < gas.length ?cost[i+j] : cost[i+j-gas.length])){
                    gas_sum -= (i + j < gas.length ?cost[i+j] : cost[i+j-gas.length]);
                    count ++;
                }

            }
            if(count == gas.length){
                return i;
            }
            count = 0;
            gas_sum = 0;
        }
        return -1;
    }
}
```