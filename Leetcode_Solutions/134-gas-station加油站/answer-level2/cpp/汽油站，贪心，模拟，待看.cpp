### 解题思路
我采用的是模拟这条策略，显然效率不是很好，但是可以将问题做出来。
模拟的策略一般容易想到，但是贪心这种方法还是要去掌握。

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int res;
         for(int i=0;i<gas.size();++i){
             res = choose(i,gas,cost);
             if(res>=0) break;
        
         }
         if(res==-1) return -1;
         else return res;
    }
    int choose(int pos,vector<int>& gas,vector<int>& cost){
        int now_gas = 0;
        int i=0;
        for(int cur = pos;cur!=pos||i==0;cur=(cur+1)%gas.size()){   // 只有当不是第一次返回起点，才可以结束循环
            now_gas+=gas[cur];  // 本来的汽油和当前位置能获得汽油
            if(now_gas-cost[cur]<0) return -1;  // 汽油不足以支持到下一个站点
            else{
                now_gas = now_gas-cost[cur];   // 能够到达下一个站点，且能剩下的汽油。
            }
            i++;
        //    cout<<i<<"  "<<cur<<endl;
        }
        return pos;
    }
};
```