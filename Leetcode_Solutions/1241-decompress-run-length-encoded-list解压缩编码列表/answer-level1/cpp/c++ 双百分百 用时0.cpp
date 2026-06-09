### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> aa;
        for(int i = 0;i<(nums.size()/2);i++){
            int freq = nums[2*i];
            int val = nums[2*i +1];
            for(int j=0;j<freq;j++){
                aa.push_back(val);
            }
        } 
        return aa;
    }
};
```