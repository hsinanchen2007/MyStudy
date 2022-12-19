### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/bd67338d0db7ab150dc6b1f40ba36b4411bf162d190634e1a91b23cef6070a0c-image.png)


### 代码

```cpp
class Solution {
public:
    // 全排列
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        
        vector<vector<int>> ans;
        if(size == 0) return ans;
        ans.push_back({});
        for(int i = 0;i<size;i++){
            int s = ans.size();
            for(int j = 0;j<s;j++){
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
```