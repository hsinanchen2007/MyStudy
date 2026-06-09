### 解题思路
找第一个乱序的数字和最后一个乱序的数字

### 代码

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int first = 0, end = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] != nums[i]){
                if(!first) first = i + 1;
                end = i + 1;
            }        
        }
        if(end == 0) return 0;
        return end - first + 1;
    }
};
```