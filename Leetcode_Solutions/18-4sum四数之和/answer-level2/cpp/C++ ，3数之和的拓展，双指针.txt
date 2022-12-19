[15.三数之和](https://leetcode-cn.com/problems/3sum/solution/cshuang-zhi-zhen-by-zgdgod-3/)
### 题解
1.前两个数字遍历
2.后两个用左右指针
3.注意不重复的判断：i>0且不与前一个相等/j>i+1且不与前一个相等/left>j+1且.../right<size-1且...

### 代码

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        vector<int> temp(4);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-1;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k=target-nums[i]-nums[j];
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    if(left>j+1&&nums[left]==nums[left-1]||nums[left]+nums[right]<k){
                        left++;
                    }else if(right<nums.size()-1&&nums[right]==nums[right+1]||nums[left]+nums[right]>k){
                        right--;
                    }else{
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[left];
                        temp[3]=nums[right];
                        res.push_back(temp);
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
```
