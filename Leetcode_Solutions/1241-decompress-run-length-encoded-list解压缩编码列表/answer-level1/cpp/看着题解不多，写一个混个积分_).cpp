
### 简单的小题
```C++
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int a, b;
        vector<int> result;
        for (int i=0; i<nums.size()-1; i+=2){
            a = nums[i]; b = nums[i+1];
            while (a--){
                result.push_back(b);
            }
        }
        return result;
    }
};
```
