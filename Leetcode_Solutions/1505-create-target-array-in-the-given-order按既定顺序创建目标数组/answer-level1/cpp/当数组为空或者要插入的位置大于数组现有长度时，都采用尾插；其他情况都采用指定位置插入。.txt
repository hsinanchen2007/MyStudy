### 解题思路
当数组为空或者要插入的位置大于数组现有长度时，都采用尾插；其他情况都采用指定位置插入。

![image.png](https://pic.leetcode-cn.com/66a86494ad7b03cb93909e59054c64ced44049733dd3ddbe4a89202666699815-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for(int i=0;i<nums.size();i++)
        {
            if(target.size()==0 || index[i] >= target.size())
                target.push_back(nums[i]);
            else 
                target.insert(target.begin()+index[i],nums[i]);
        }
        return target;
    }
};
```