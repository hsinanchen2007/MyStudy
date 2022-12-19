### 解题思路
递归求解。
`[1]`的全排列是`[1]`
`[1,2]`的全排列，可看成是将`2`在可插入位置插入`[1]`，得到`[1,2]`,`[2,1]`
`[1,2,3]`的全排列，可看成是将`3`在可插入位置插入`[1,2]`

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1) 
        {
            vector<vector<int>> v { nums };
            return v;
        }
        else
        {
            vector<vector<int>> result;
            int backElement = nums[nums.size()-1];
            nums.pop_back(); // 取出末尾元素
            auto rv = permute(nums); // 剩余元素做全排列
            result = insertNewElement(rv, backElement);
            return result;
        }
        
    }

    vector<vector<int>> insertNewElement(vector<vector<int>> arr, int x)
    {
        vector<vector<int>> result;
        // 以插入的方式生成新的全排列
        for(int i=0; i<arr.size(); i++)
        {
            int size = arr[i].size();
            for(int j=0; j<size; j++)
            {
                auto temp = arr[i];
                auto itbegin = temp.begin();
                temp.insert(itbegin+j, x);
                result.push_back(temp);
            }
            auto temp = arr[i];
            temp.push_back(x);
            result.push_back(temp);
        }
        return result;
    }
};
```