### 解题思路
![image.png](https://pic.leetcode-cn.com/f392a7487e4546e50609d7cbc1374c3be9ab6910920da59c2b580c88a92d1115-image.png)

第一次不偷第一家，第二次偷第一家

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        int unsteal=0,steal=nums[1];
        for(int i=2;i<nums.size();i++)
        {
            int tmp=steal;
            steal=unsteal+nums[i];
            unsteal=max(unsteal,tmp);
        }

        int steal2=nums[0],unsteal2=nums[0];
        for(int i=2;i<nums.size()-1;i++)
        {
            int tmp=steal2;
            steal2=unsteal2+nums[i];
            unsteal2=max(unsteal2,tmp);
        }

        return max(max(steal,unsteal),max(steal2,unsteal2));


    }
};
```