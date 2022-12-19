### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int total=0;
    void DFS(vector<int>&nums,int level,int sum,int S){
        if(level==nums.size()){
            if(sum==S)
                total++;
            return;
        }
        DFS(nums,level+1,sum+nums[level],S);
        DFS(nums,level+1,sum-nums[level],S);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        DFS(nums,0,0,S);
        return total;
    }
};
```