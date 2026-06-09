### 解题双指针

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int index1 = 0;
        int index2 = n-1;
        while( numbers[index1] + numbers[index2] != target ){
            if(numbers[index1] + numbers[index2] < target)index1++;
            if(numbers[index1] + numbers[index2] > target)index2--;
        }
        return{index1+1,index2+1};
    }
};
```