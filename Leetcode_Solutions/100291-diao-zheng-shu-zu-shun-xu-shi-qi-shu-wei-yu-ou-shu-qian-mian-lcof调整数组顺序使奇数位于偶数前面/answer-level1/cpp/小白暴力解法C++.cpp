
直接遍历整个数组，奇数为一个新数组，偶数为一个新数组，再将偶数组插入到奇数组后面；


```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int>ans1,ans2;
        for(int i = 0; i < nums.size();i++){
            if(nums[i]%2 !=0)
                ans1.push_back(nums[i]);
            else
                ans2.push_back(nums[i]);
        }
        for(int j = 0; j < ans2.size();j++)
            ans1.push_back(ans2[j]);
        return ans1;
    }
};
```