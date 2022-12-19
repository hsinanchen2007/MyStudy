### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1 = 0;
        int len = 0;
        for(int i = 0;i < nums.size();i++){
            if (nums[i]==1){
                len++;
                max1 = max(max1,len);
            }
            else{
                
                len =0;
            }
        }
        return max1;
    }
};
```