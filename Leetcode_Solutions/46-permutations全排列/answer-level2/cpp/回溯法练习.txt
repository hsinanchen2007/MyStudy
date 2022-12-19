### 解题思路

1. **数组nums，一个解temp，所有解（输出）res**
2. **主函数中，读入数组nums**
3. **func函数中，读入数组nums，改变temp**
4. **temp保留过程，temp为一个解时，push进res中  ///res为全局变量**

1. **用flag来保证数字不重复**
2. **如果序列中有重复数字，则需要另行他法**

### 代码

```cpp
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> temp;
        func(0,nums,temp);
        return res;
        
    }

    void func(int i,vector<int> nums,vector<int>& temp)
    {
        if(i>=nums.size())
        {
            res.push_back(temp);
        }
        else
        {
            int flag=0;
            for(int j=0;j<nums.size();++j)
            {
                for(int k=0; k<temp.size(); ++k)
                {
                    if(temp[k]==nums[j])
                    flag=1;
                }
                if(flag!=1)
                {
                    temp.push_back(nums[j]);
                    func(i+1,nums,temp);
                    temp.pop_back();
                }
                flag=0;
            }

        }
    }
};
```