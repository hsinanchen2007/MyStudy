### 解题思路
此处撰写解题思路

### 代码

```cpp
//小贴士： 采取验证hash的做法，但是这里顺序是不确定的，所以得找一个与位置无关的值, 很明显总和，总积都是不变量
// 一个我没想到的点是： 还有他们的异或也是不变量

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n;i++) {
            sum += nums[i];
        }
        return (n + 1) * n / 2 - sum;
    }
};
```