

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return -1;

        int n=nums.size();
        map<int,int> help;
        for(int num:nums)
            help[num]++;
        
        for(int num:nums)
            if(help[num]>n/2) return num;
        
        return -1;
    }
};
```