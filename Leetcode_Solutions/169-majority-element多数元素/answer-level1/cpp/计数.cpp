### 解题思路


### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1,word = nums[0],i = 0;
        while(++i < nums.size()){
            if(nums[i] == word) cnt++;
            else{
                cnt--;
                if(cnt == 0){
                    cnt = 1;
                    word = nums[i];
                }
            }
        }
        return word;
    }
};
```