### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0,high=numbers.size()-1;
        while(low < high) {
            int sum = numbers[low] + numbers[high];
            int mid = (low+high)/2;
            if(sum > target)
                --high;
            else if(numbers[low]+numbers[high] < target)
                ++low;
            else
                return {low+1, high+1};
        }
        return {};
    }
};
```
第一天开始刷题，加油！！坚持！