### 解题思路
该问题求解的是从某一点出发，使得加油站加油与耗油之差始终大于0走完整个环路。实际上就是求解该环路的一个最大连续子序列，与求解线性序列的最大子序列的在线更新算法有所不同的是，需要遍历两次该环路来求解最大子序列以保证考虑到循环的情况，其余与线性序列的最大子序列的求法一致，最终时间复杂度为O（N)

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //便于理解使用一个compute数组，但是耗费较多的空间
        int compute[gas.size()];
        for(int i=0;i<gas.size();i++)
        compute[i]=gas[i]-cost[i];
        int maxnow=-1;
        int now=0;
        int sum=0;
        int maxval=-1;
        int count=0;
        for(int i=0;count<2*gas.size();i=(i+1)%gas.size()){
            count++;
            sum+=compute[i];
            
            if(sum<0){
                sum=0;
                now=i+1;
            }
            else if(sum>maxnow){
                maxnow=sum;
                maxval=now;
            }
        }
        if(maxval==-1)
        return -1;
    
        sum=0;
        count=0;
        for(int i=maxval;count<gas.size();i=(i+1)%gas.size()){
            count++;
            sum+=compute[i];         
            if(sum<0)
            return -1;
        }
        return maxval;
    }
};
```