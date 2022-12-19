### 解题思路
![}$C_CPG2CAU$8B{4{599}CR.png](https://pic.leetcode-cn.com/31d65d4c4881b8438b6d3a6ec093380d46b0cc6b01552af38bf8f1c5cd8e8473-%7D$C_CPG2CAU$8B%7B4%7B599%7DCR.png)
此处撰写解题思路
他站在第一个位置上，初始化dp[1]=true;
向前递归如果他前面存在可以从第一个位置跳达的k位置，并且他与k位置距离小于等于
k位置的最大跳跃步数，此时说明它也可以跳达；循环迭代，返回dp[n]即可。
### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[nums.size()+1];
    //    dp[0]=true;
        dp[1]=true;
        for(int j=2;j<=nums.size();j++){
            for(int k=j-1;k>0;k--){
                if(dp[j]=(dp[k]&&((j-k)<=nums[k-1])))  break;
            }
        }
        return dp[nums.size()];
    }
};
```