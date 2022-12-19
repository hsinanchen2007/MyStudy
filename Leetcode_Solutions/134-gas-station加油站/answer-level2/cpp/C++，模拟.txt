### 解题思路
遍历，模拟走路；
把每一个位置当为开始，看能不能走完这一圈；
每次比较剩余汽油+加油>=路程才继续

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len=cost.size();
        int res=-1;
        for(int i=0;i<len;i++){
            int sum=0; //模拟，目前的石油剩余和，从第i加油站开始
            int flag=0;    //标志位
            for(int j=i;j<len;j++){
                if(gas[j]+sum>=cost[j]){
                    sum+=gas[j]-cost[j];
                }else{
                    flag=1;
                    break;
                }
            }
            if(flag==1) continue;   //后半段不满足，直接进行下次循环
            for(int j=0;j<=i;j++){
                if(gas[j]+sum>=cost[j]){
                    sum+=gas[j]-cost[j];
                }else{
                    break;
                }
                if(j==i) {
                    res=j;
                    flag=2;         //找到结果，直接返回
                    break;
                }
            }
            if(flag==2) break;
        }
        return res;
    }
};
```