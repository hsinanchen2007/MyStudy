### 解题思路
利用没有重复数字的全排列代码，加上剪枝

### 代码
![图片.png](https://pic.leetcode-cn.com/dd2151b4e89a678e3a414a39a8d5ac2b02e95ea132e2908f258e9509f80f7f8c-%E5%9B%BE%E7%89%87.png)

```cpp
class Solution {
public:
    void DFS(vector<int>& nums, vector<vector<int>>& ret, int *visited, int cnt, vector<int>& tmp)
    {
        int i;
        if (cnt == nums.size()){
            ret.push_back(tmp);
            return;
        }
        for (i = 0; i<nums.size(); i++){
            if (0 == visited[i]) {
                if(i>0 && nums[i]==nums[i-1] && visited[i-1]!=0) continue; //剪枝
                visited[i] = 1;
                tmp.push_back(nums[i]);
                DFS(nums, ret, visited, cnt + 1, tmp);
                tmp.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int *visited = (int*)malloc(nums.size()*sizeof(int));
        memset(visited, 0, nums.size()*sizeof(int));
        vector<vector<int>> ret;
        vector<int> tmp;
        int cnt = 0;
        sort(nums.begin(), nums.end()); //会出现[3,0,3,3]这种情况，所以要排序
        DFS(nums, ret, visited, cnt, tmp);
        return ret;
    }
};

//第二种方法利用set暴力去重
![图片.png](https://pic.leetcode-cn.com/c63316c760a56fae6d07e1b9acd3f5b877175029f19b359819cb7d095df505e9-%E5%9B%BE%E7%89%87.png)
class Solution {
public:
    void DFS(vector<int>& nums, set<vector<int>>& ans, int *visited, int cnt, vector<int>& tmp)
    {
        int i;
        if (cnt == nums.size()){
			ans.insert(tmp);
            return;
        }
        for (i = 0; i<nums.size(); i++){
            if (0 == visited[i]) {
                visited[i] = 1;
                tmp.push_back(nums[i]);
                DFS(nums, ans, visited, cnt + 1, tmp);
                tmp.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int *visited = (int*)malloc(nums.size()*sizeof(int));
        memset(visited, 0, nums.size()*sizeof(int));
        vector<vector<int>> ret;
		set<vector<int>> ans;
        vector<int> tmp;
        int cnt = 0;
        DFS(nums, ans, visited, cnt, tmp);
		ret.assign(ans.begin(), ans.end());
        return ret;
    }
};

```


