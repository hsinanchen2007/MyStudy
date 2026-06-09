### 解题思路
首先，将全部的人去A市，计算总和sum；然后计算每一个人去A市比去B市多的价钱（差额），根据差额的大小进行排序，用sum减去差额最大的前一半的钱数
即在原来sum的基础上减去去A 市花费最多人数前一半的和，加上去B市花费最少前一半的人数的花费，即得到最低总费用。

### 代码

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0;

        for(int i=0;i<costs.size();i++){
            sum+=costs[i][0];
        }

        vector<int>arr;
        for(int i=0;i<costs.size();i++){
            arr.push_back(costs[i][0]-costs[i][1]);
        }
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<arr.size()/2;i++){
            sum-=arr[i];
        }
        return sum;
        
    }

};
```