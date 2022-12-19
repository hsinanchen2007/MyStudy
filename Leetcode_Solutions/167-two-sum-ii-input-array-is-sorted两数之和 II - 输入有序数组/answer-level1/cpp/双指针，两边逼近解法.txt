### 解题思路
两边逼近

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for(int i = 0,j = numbers.size() - 1; i < j;){
            while(numbers[j] > target - numbers[i] && i < j) j--;
            while(numbers[i] < target - numbers[j] && i < j) i++;
            if(numbers[i] + numbers[j] == target) {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            }
        }
        return result;
    }
};
```