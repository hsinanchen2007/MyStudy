### 解题思路
官方写法c++版

### 代码

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int max_count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
                if(count>=max_count){
                    max_count=count;
                }
                count=0;
            }
        }
        return max(max_count,count);

    }
};
```