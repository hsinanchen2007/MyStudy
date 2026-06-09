### 解题思路

当nums.size()<=2的时候不需要添加括号
当nums.size()>2时，只要满足被除数最大，除数最小即可，用一个括号即可完成！

### 代码

```cpp
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res="";
        if(nums.size()==1)
            return to_string(nums[0]);
        else if(nums.size()==2)
            return to_string(nums[0])+"/"+to_string(nums[1]);
        for(int i=0;i<nums.size();++i)
        {
            if(i==0)
                res+=to_string(nums[i])+"/(";
            else if(i!=nums.size()-1)
                res+=to_string(nums[i])+"/";
            else
                res+=to_string(nums[i])+")";
        }
        return res;
    }
};
```