### 解题思路
求极值，优化问题。
首先写出优化问题的数学表达式：
![QQ图片20191212114913.png](https://pic.leetcode-cn.com/37bb4124855a595d0b3c0668817ff599936b4b28f007290ff8c16533a4ae0199-QQ%E5%9B%BE%E7%89%8720191212114913.png)
化简后得：
![QQ图片20191212115343.png](https://pic.leetcode-cn.com/42b2d34c954206ef298627266be6991d216104cbaeec584f5db770a4e3f13e56-QQ%E5%9B%BE%E7%89%8720191212115343.png)
可见只需找到最小的N个差（A-B）即可，然后再加上A的所有费用。

### 代码

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=0;
        vector<int> diff;
        for(int i=0;i<costs.size();i++){
            diff.push_back(costs[i][0]-costs[i][1]);
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<diff.size();i++){
            ans = ans + costs[i][1];
            if(i<diff.size()/2){
                ans=ans+diff[i];
            }
        }
        return ans;
        
    }
};
```