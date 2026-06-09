### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int>vec(nums);
        int len=nums.size();
        vector<int>ans;
        for(int i=0;i<len;i++){
            vec.push_back(nums[i]);
        }
        for(int j=0;j<len;j++){
            ans.push_back(vec[j+len-k]);//这一步最为重要
        }
        nums=ans;
    }
};
```