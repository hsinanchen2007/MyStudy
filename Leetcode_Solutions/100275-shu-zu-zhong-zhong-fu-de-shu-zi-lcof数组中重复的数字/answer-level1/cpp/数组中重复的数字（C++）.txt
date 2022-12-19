### 解题思路
这个题简直简单到没有题解，一个map，num -> sum，数和次数对应就搞定了。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 一个map就搞定了
        map<int, int> numSum; // num -> sum
        for (int i = 0; i < nums.size(); i++) {
            numSum[nums[i]] += 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (numSum[nums[i]] > 1)
                return nums[i];
        }
        return 0;
    }
};
```