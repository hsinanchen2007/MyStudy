

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> help;

        for(int num:nums)
        {
            help[num]++;
            if(help[num]>n/2) return num;
        }

        return -1;
    }
};
```