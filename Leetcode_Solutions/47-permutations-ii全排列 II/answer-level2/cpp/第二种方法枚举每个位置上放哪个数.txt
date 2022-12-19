### 解题思路 
![H8e024c0f60ed49e1afbe54d3334f8a58R.png](https://pic.leetcode-cn.com/c1af774083c221f7bbe09d58ff2968add9287324e7e834136aa7e504f9d67d3e-H8e024c0f60ed49e1afbe54d3334f8a58R.png)
这题剪枝的前提需要先排序，排序后所有相等的数全部都靠在一起

碰到重复元素会有两种情况
1.这个数正在被使用，那么下一个位置能够摆上相同的数字
2.这个数刚刚被撤销，如果下一个位置摆上刚才撤销回来的数字，那么递归树必然和撤销前的递归树重复，所以应该剪枝
### 代码

```cpp
class Solution {
public:
    int n;
    vector<vector<int>>ans;
    vector<int>path;
    vector<bool>st;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        st = vector<bool>(n);
        path = vector<int>(n);
        sort(nums.begin(),nums.end());
        dfs(nums,0,0);
        return ans; 
    }
    void dfs( vector<int>&nums,int u , int index){
        if(u == n){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){
            if(i > 0 && st[i - 1] && nums[i - 1] == nums[i])continue;
            if(!st[i]){
                st[i] =true;
                path[index] = nums[i];
                dfs(nums, u + 1, index + 1);
                st[i] = false;

            }
        }
    }
};
```