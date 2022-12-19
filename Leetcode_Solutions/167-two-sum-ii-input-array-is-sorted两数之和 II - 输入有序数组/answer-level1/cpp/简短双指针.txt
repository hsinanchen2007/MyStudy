### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        while (numbers[i] + numbers[j] != target)
        {
            while (numbers[i] + numbers[j] > target) j--;
            while (numbers[i] + numbers[j] < target) i++;
        }
        return {i + 1, j + 1};
    }
};
```