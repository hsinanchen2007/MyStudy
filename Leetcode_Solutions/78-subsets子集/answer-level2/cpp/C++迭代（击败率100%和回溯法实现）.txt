### 解题思路
![1.jpg](https://pic.leetcode-cn.com/0fd9f802655637ed3cbcdda86b1b22ce8633c21854d3439a54820cec7b97d336-1.jpg)

### 代码

```cpp
class Solution {
public:
    //1.迭代方法
    //首先为空[] 
    // [] [1] 第一次遍历
    // [] [1] [2] [1,2] 第二次遍历
    // [] [1] [2] [1,2] [3] [1,3] [2,3] [1,2,3] 第三次遍历
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for(int i=0;i<nums.size();i++)
        {
            vector<int> list;
            int length = result.size();
            for(int j=0;j<length;j++) //length每次都在变
            {
                list = result[j];
                list.push_back(nums[i]);
                result.push_back(list);
            } 
        }
        return result;
    }

    //2.使用递归，回溯算法

    void dfs(vector<int>& nums,vector<vector<int>>&ans,int index,vector<int>& vec)
    {
        //terminator
        if(index == nums.size())
        {
            ans.push_back(vec);
            return;
        }
        //drill down
        dfs(nums,ans,index+1,vec);//not pick number
        //process
        vec.push_back(nums[index]); //add number
        dfs(nums,ans,index+1,vec);//pick number
        
        //reverse current state
        vec.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        vector<int> vec;
        dfs(nums,ans,0,vec);
        return ans;
    }
};
```