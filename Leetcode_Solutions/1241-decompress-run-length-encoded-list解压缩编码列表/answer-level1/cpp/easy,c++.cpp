### 解题思路
遍历即可

### 代码

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size()-1;i=i+2){
            int a=nums[i],b=nums[i+1];
            for(int j=0;j<a;j++){
                res.push_back(b);
            }
        }
        return res;
    }
};
```