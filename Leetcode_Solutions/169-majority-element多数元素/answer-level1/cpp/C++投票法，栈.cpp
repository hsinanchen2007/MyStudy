### 解题思路
利用了栈进行投票

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> num;
        for(int i=0;i<nums.size();i++){
            if(num.empty()){
                num.push(nums[i]);
                continue;
            }
            if(nums[i]!=num.top()){
                num.pop();
            }
            else{
                num.push(nums[i]);
            }
        }
        return num.top();
    }
};
```