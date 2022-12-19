### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //先排序
        sort(nums.begin(), nums.end());
        vector<int> ans;
        //重复元素
        int a = -1;
        //缺失元素
        int b = -1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            //找出重复元素
            if(nums[i] == nums[i + 1])
                a = nums[i];
            //找出缺失元素
            if(nums[i+1] - nums[i] > 1){
                b = nums[i] + 1;
            }
            if(a != -1 && b != -1)
                break;
        }
        //分别保存重复元素和缺失元素
        if(a!=-1)
            ans.push_back(a);
        if(b!=-1)
            ans.push_back(b);
        //缺失元素为 n 或 1
        if(ans.size() < 2)
        {
            if(nums[0] != 1)
                ans.push_back(1);
            else 
                ans.push_back(nums.size());
        }
        return ans;
    }
};
```