### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
    int i = 1; // 滑动窗口的左边界
    int j = 1; // 滑动窗口的右边界
    int sum = 0; // 滑动窗口中数字的和
    vector<vector<int>> res;
    while (i <= target / 2) {
            if (sum < target)
            {
            // 右边界向右移动
                sum += j;
                j++;
            } 
            else if (sum > target) {
            // 左边界向右移动
            sum -= i;
            i++;
            } 
            else 
            {
                // 记录结果
                vector<int> arr;
                for (int k = i; k < j; k++) {
                    arr.push_back(k);
                }
                res.push_back(arr);
                // 左边界向右移动
                sum -= i;
                i++;
            }
        }
        return res;
    }
};
```