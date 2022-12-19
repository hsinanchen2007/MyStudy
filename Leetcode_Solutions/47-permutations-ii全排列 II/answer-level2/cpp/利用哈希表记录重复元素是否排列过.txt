### 解题思路
求不重复序列的全排列方法：
将每个元素与第一个元素交换，求后面n-1个元素的全排列
求重复序列的全排列方法在求不重复序列的全排列基础上，增加一个哈希表，对于任意一个元素，与第一个交换并做排列时，先检测哈希表对应位置是否为1：
若不是，则与第一个元素交换，求后面n-1个的排列，求完后换回来，同时对应的哈希表位置置1；
若是，表示以该值开头已经排过了，那就不做操作，直接进入下一次循环

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        muteUnique(nums,nums.size());
        return res;
    }
    void muteUnique(vector<int>& nums,int n)
    {
        if(!n) res.push_back(nums);
        else
        {
            unordered_map<int,int> used;
            for(int i=nums.size()-n;i<nums.size();i++)
            {
               //如果以nums[i]开头的已经排过了，那么就不进行交换
                if(used[nums[i]] == 1) continue;
                else
                {
                    //和第一个交换
                    int tmp=nums[i];
                    nums[i]=nums[nums.size()-n];
                    nums[nums.size()-n]=tmp;
                    //求后面n-1个的不重复全排列
                    muteUnique(nums,n-1);
                    //回溯，换回来
                    tmp=nums[i];
                    nums[i]=nums[nums.size()-n];
                    nums[nums.size()-n]=tmp;
                    //以nums[i]开头的已经排过了
                    used[nums[i]] =1;
                }
            }
        }
    }
};
```