### 解题思路
摩尔投票法，采用抵消思想
假设第一个数是多数元素，遍历，遇到和第一个数相同，则count++，否则count--，当count=0时，换下一个数

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int temp2 = nums[0];
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                temp2 = nums[i];
                count++;
            }else{
                temp2==nums[i]?count++:count--;
            }
        } 
        return temp2;   
    }
};
```