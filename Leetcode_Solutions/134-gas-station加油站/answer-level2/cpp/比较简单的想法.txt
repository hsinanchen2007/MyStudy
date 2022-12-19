先检查是否有解，有解的话必然是`sum(gas)>=sum(cost)`，否则直接`return -1`.
有解的情况必然也是从`gas[i]>=cost[i]`开始。然后记录下当前`i`，如果从当前`i`可以到达最后，那么这个`i`就是要返回的（题目保证了有唯一解），否则的话找下一个`gas[i]>=cost[i]`

```

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0,current_station=0;
        bool flag=false;
        //是否有解
        for(int i=0;i<gas.size();i++){
            total_gas+=gas[i]-cost[i];
        }
        if(total_gas<0)return -1;
        //有解遍历
        for(int i=0;i<gas.size();i++){
            if(gas[i]<cost[i])continue;//有解的话必然是从cost[i]<=gas[i]开始
            total_gas=0;
            for(int j=i;j<gas.size();j++){
                current_station=i;
                total_gas+=gas[j]-cost[j];
                if(total_gas<0){//i到不了j，直接结束当前循环
                    break;
                }
                if(j==gas.size()-1){//能走到最后，设置标志位，结束第一层循环
                    flag=true;
                }

            }
            if(flag)break;
            
        }
        return current_station;
    }
};
```

- 官方O(n)解法，证明看官方就可以了
```

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int total_gas=0,current_gas=0,current_station=0;
//         for(int i=0;i<gas.size();i++){
//             total_gas+=gas[i]-cost[i];
//             current_gas+=gas[i]-cost[i];
//             if(0>current_gas){
//                 current_station=i+1;
//                 current_gas=0;
//             }
//         }
//         return total_gas>=0?current_station:-1;
//     }
// };


```
