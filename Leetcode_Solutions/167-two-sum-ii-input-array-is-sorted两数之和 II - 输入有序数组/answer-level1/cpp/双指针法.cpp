### 解题思路
左右两个指针分别初始化为数组的第一个下标和数组的最后一个下标
小于目标值则left++，大于目标值则right--，直到满足两项之和等于目标值则跳出while循环
将left和right值分别+1后返回
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int temp = numbers[left] + numbers[right];
        while (temp != target)
        {
            if (temp > target)
                right--;
            if (temp < target)
                left++;
            temp = numbers[left] + numbers[right];
        }
        vector<int> res;
        res.push_back(left+1);
        res.push_back(right+1);
        return res;
    }
};
```