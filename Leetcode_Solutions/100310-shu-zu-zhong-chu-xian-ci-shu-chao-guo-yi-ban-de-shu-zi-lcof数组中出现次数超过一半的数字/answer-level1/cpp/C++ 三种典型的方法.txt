### 解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //方法1：排序后中间的元素一定是出现超过一半的数字
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];

        //方法2：哈希表
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
            if(mp[it]>nums.size()/2) return it;
        }
        return 0;

        //方法3：超过一半的数字比其他所有数字的总和次数多
        int n=1;
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(n==0){
                result=nums[i];
                n=1;
            }
            else if(result==nums[i])n++;
            else n--;
        }
        return result;
    }
};
```