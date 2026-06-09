### 解题思路
利用双指针的思路，如果当前结果比target小，前指针后移，如果当前结果比target大，后指针前移，当前结果和target相等，则返回当前index。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p = 0;
        int q = n - 1;
        vector<int> ans;
        while(p < q){
            if(numbers[p] + numbers[q] == target){
                ans.push_back(p + 1);
                ans.push_back(q + 1);
                break;
            }
            if(numbers[p] + numbers[q] < target)
                p++;
            if(numbers[p] + numbers[q] > target)
                q--;
        }
        return ans;
    }
};
```