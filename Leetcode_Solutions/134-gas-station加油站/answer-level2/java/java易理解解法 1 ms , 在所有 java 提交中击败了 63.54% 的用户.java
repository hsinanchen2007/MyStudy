### 解题思路
1.判断总量是否足够全程，不行返回-1
2.从第一个加油站gas[0]开始，i=0
3.rest=rest+gas[i]-cost[i]
4.小于零则起始站换成下一站
5.上一步如果在数组最后一位，则i=0,否则i+=1
6.每次更新star，跳出while后返回star
### 代码

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int i=0,rest=0,stop=1,j,star=i,sum_gas=0,sum_cost=0;
        for(int k=0;k<gas.length;k++){
            sum_gas+=gas[k];
            sum_cost+=cost[k];
        }
        if(sum_gas<sum_cost){
            return -1;
        }
        while(stop<=gas.length-1){
            rest=rest+gas[i]-cost[i];//you are at i+1 stop
            if(rest<0){
                if(i==gas.length-1){
                    i=0;
                    star=i;
                }
                else{
                    i=i+1;
                    star=i;
                }
                rest=0;
                stop=0;
            }
            else{
                if(i==gas.length-1){
                    i=0;
                }
                else{
                    i=i+1;
                }
                stop++;
            }
        }
        return star;
    }
}
```