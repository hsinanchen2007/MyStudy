### 解题思路
使用自带的sort函数（时间复杂度O(nlogn)）进行排序后，再进行一次遍历获得最大间距。
时间复杂度为O(nlogn)

### 代码

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        if(len < 2)
            return ans;
        
        sort(nums.begin(), nums.end());

        for (int i=0; i<len-1; i++) 
            ans = nums[i+1]-nums[i]>ans?nums[i+1]-nums[i]:ans;

        return ans;
    }  
};
```