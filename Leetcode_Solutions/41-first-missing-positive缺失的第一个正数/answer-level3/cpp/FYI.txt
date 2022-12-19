### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = nums.begin();
        int result = 1;
        for ( ;it != nums.end();it++ ) {
            if ( *it <= 0 ) {
                continue;
            }
            if ( *it > result ) {
                return result;
            } else {
                result = *it + 1;
            }
        }
        return result;
    }
};
```