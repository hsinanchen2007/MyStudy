想不出来没有各位聪明才智只好暴力解决了
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        if (!nums.empty()) res.push_back({});
        //循环nums数组依次添加到res中
        for (int i = 0; i < nums.size(); i++)               
        {
            res.push_back(vector<int> {nums[i]});
            int len = res.size();
            //循环res数组依次在尾部添加nums，并加入res中
            for (int j = 1; j < len - 1; j++)
            {
                vector<int> temp;
                for (int z = 0; z < res[j].size(); z++)
                {
                    temp.push_back(res[j][z]);
                }
                temp.push_back (nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};

```
