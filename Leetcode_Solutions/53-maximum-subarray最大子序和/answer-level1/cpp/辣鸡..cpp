### 解题思路
此处撰写解题思路
很显然,这段代码就是个辣鸡.
### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int *p=new int[nums.size()+2];
        p[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            p[i]=p[i-1]+nums[i];
        int MAX=(1<<31);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                MAX=MAX>p[j]-p[i]+nums[i]?MAX:p[j]-p[i]+nums[i];
            }
        }
        return MAX;
    }
};
```