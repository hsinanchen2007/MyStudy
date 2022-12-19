### 解题思路
双指针固然优秀。从前往后遍历，对每一个元素，二分查找其后的元素中是否有与其和为目标值的。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] <= target) {// 因为numbers中可能有元素0，所以是<=而非<
                int n = target - numbers[i];
                int lo = i + 1, hi = numbers.size();
                while (lo < hi) {
                    int mi = (lo + hi) >> 1;
                    n < numbers[mi] ? hi = mi : lo = mi + 1;
                }
                if (numbers[lo - 1] == n)
                    return vector<int>{i + 1, lo};
            }
        }
        return vector<int>{0, 0};// 无意义
    }
};
```