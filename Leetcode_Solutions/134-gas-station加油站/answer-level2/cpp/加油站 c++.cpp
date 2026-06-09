### 解题思路
我们其实只要找出能通过的可能性最大的那个点就行，可以令c[i]=gas[i]-cost[i],代表这个点的油量净变化值，
我们只要找到一个净变化值之和最大的连续序列，那么这个序列的起点就是最有可能的点。
还要排除不可能的情况，就是gas[i]之和小于cost[i]之和。

### 代码

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gassum=0,costsum=0;
        int max=INT_MIN;
        int start=0;
        int lastsum=0;
        int res=-1;
        for (int i=0;i<n;i++){
            int s=gas[i]-cost[i];
            gassum+=gas[i];
            costsum+=cost[i];
            if (lastsum>0){
                lastsum+=s;
            }
            else{
                lastsum=s;
                start=i;
            }
            if (lastsum>max){
                res=start;

            }
        }
        if (costsum>gassum){
            return -1;
        }
        return res;

    }
};
```