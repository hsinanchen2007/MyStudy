### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1,right = 1,sum = 0; 
        //存储返回值的数组
        vector<vector<int>> res;
        while (left <= target / 2) {
            if (sum < target) {
                // 如果和小于target，右边界向右移动
                sum += right;
                right++;
            } else if (sum > target) {
                // 如果和大于target，左边界向右移动
                sum -= left;
                left++;
            } else {
                vector<int> arr;
                for (int k = left; k < right; k++) {
                    arr.push_back(k);
                }
                res.push_back(arr);
                // 向左移动,因为右边界的值较大，可能会跳过选项，因此往左边界移动。
                sum -= left;
                left++;
            }
        }
        return res;
    }
};
```