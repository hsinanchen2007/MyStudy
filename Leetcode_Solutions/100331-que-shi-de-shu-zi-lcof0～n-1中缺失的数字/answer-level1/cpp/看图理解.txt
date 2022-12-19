### 解题思路
当出现第一个nums[index] != index，则index为缺失的数
![queshi.png](https://pic.leetcode-cn.com/eafc896d89713ee4d0ae93e6350cf1203e039bb5bb4ced2527776eeeca924c8c-queshi.png)

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int index;
        for(index = 0; index < nums.size(); ++index)
        {
            if(index != nums[index])
                break;
        }
        return index;
    }
};
```