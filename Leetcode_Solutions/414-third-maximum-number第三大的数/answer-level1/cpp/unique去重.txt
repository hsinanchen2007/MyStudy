### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int>::iterator iter;   
        sort(nums.begin(),nums.end(),greater<int>());
        //reverse(nums.begin(),nums.end()); //反转      
        iter=unique(nums.begin(),nums.end());
        if(iter!=nums.end())
        {
            nums.erase(iter,nums.end());
        }
          
        if(nums.size()<3)
        {
            return nums[0];
        }else return nums[2];
    }
};

终于写出来了！可惜调用了unique函数，大家请见谅！！
```