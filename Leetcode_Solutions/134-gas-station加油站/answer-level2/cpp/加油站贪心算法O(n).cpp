从头到尾遍历一次找出最佳起点或者判断出永远不能满足。
对于∑(gas[i]-cost[i]) 
A:小于零，永远不能满足，直接返回-1;  
B:大于等于零，至少存在一个起点可以绕环行走一圈。
对于情况B: 假设当前加油站为起点start，sub[i]=gas[i]-cost[i];借用一个变量xtoy记录用于记录start加油站开始，加油与耗油差值的总和;
如果xtoy <0，说明从start到当前没有合适的起点（因为sub[i]>0,才有可能是起点，那么sub[start]一定大于零，所以start,start+1...当前,都不满足），因此把当前最佳起点定为下一个加油站，而xtoy也要置零，因为要判断从下一个加油站作为start是否满足贪心条件;
```
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int toal=0;//记录总计的加油与耗油差值，判断是否为永久不满足
        int start=0;//一开始可能起点为0
        int xtoy=0;//用于记录start加油站开始，加油与耗油差值的总和
        for(int i=0;i<gas.size();++i){
            int sub=gas[i]=cost[i];//加油与耗油的差值
            toal+=sub;//差值求和
            xtoy+=sub;//start加油站开始，差值求和
            if(xtoy<0){//小于零说明从start到当前没有合适的起点
                xtoy=0;//置零用于重新记录下一个候选起点
                start=i+1;//当前可能起点为i+1;
            }
        }
        return toal<0?-1:start;
    }
};
```
