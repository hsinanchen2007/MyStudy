### 解题思路
循环一次即可。

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();

        int total=0;
        int curr=0;
        int st=0;
        for(int i=0;i<n;++i)
        {
            int tmp=gas[i]-cost[i];
            total+=tmp;
            curr+=tmp;
            if(curr<0)
            {
                st=i+1;
                curr=0;
            }
        }
        return total>=0?st:-1;
    }
};
```