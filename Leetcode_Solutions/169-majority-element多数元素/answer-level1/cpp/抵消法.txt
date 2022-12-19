### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentNumber = nums[0];
        int sum = 1;
        for(int i = 1;i<nums.size();i++){
            if(currentNumber != nums[i])
                sum--;
            else
                sum++;
            if(0 == sum){
                currentNumber = nums[++i];
                sum = 1;
            }
        }
        return currentNumber;
    }
};
```