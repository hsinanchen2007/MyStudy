### 解题思路
先将int类型转换为str类型，然后在计算有多少位数字
需要包含头文件：#include <sstream>
执行用时长，效率不高。
### 代码

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for (int i=0; i<nums.size(); i++){
            //string str;
            ostringstream convert;
            convert<<nums[i];
            //str=convert.str();
            if (convert.str().size()%2==0)
                ans++;
        }
        return ans;
    }
};
```