### 解题思路
首尾向内压缩

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int cl = numbers[left];
            int expect = target - cl;

            while (numbers[right] > expect) {
                right--;
            }
            if (numbers[right] == expect) {
                return vector<int>({left + 1, right + 1});
            }
            left++;
        }
        return vector<int>();
    }
};
```