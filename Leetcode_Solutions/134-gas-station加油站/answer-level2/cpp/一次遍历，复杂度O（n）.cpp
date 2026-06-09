
```c++ []
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int min(1000);
        int fee(0);
        int index(0);
        for(int i = 0; i < gas.size(); i++)
        {
            fee += gas[i] - cost[i];
            if(min > fee)  
            {
                index=i;
                min = fee;
            }
        }
        index++;
        fee = 0;
        cout<<index;
        for(int i = index;i < gas.size()+index;i++)
        {
            int temp = i % gas.size();
            fee += gas[temp] - cost[temp];
            if(fee < 0)
                return -1;
        }
        return index%gas.size();
    }
};
```
先从头开始走，记录下最缺油的时刻，遍历一次，（最缺油的时刻就是剩余油量fee最小的时刻），找到这个油站index后，它的下一个油站index++就是最理想的出发点。

然后验证从index++，油站出发，看整个过程中油量有没有出现负数，若出现则返回-1。完成所有油站的遍历后，返回index，即出发油站。

时间复杂度O（n）。