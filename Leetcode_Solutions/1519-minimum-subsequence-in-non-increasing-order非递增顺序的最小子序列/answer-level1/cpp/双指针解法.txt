### 解题思路
此处撰写解题思路
先排序，然后左右双指针，如果左边的leftsum加上当前nums[left]大于等于rightsum，则将nums[right]存入，并更新左右指针。
### 代码

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size()==1) return nums;
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        vector<int> ans;
        int leftsum=0,rightsum=0;
        while(left<=right){
            if(rightsum<=leftsum+nums[left]){
                rightsum+=nums[right];
                ans.push_back(nums[right]);
                right--;
                
            }else{
                leftsum+=nums[left];
                left++;
            }
        }
        return ans;
    }
};
```