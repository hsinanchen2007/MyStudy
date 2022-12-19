### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool pathOk(int startIdx,vector<int>& gas, vector<int>& cost)
    {
        int sum = 0;
        for(int i = startIdx; i < gas.size();i++)
        {
            sum = sum + gas[i] - cost[i];
            if(sum<0)return false;
        }
        for(int i = 0; i < startIdx;i++)
        {
            sum = sum + gas[i] - cost[i];
            if(sum<0)return false;
        }
        return true;

    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size();i++)
        {
            if(gas[i] < cost[i])continue;
            if(pathOk(i,gas,cost))
            {
                return i;
            }
        }
        return -1;        
    }
};
```