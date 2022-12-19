### 解题思路
直接看代码吧，暴力法没啥思路。！！！！！！

### 代码

```cpp
/*暴力法也可以通过，但是最好是二分法*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> resultRange(2,-1);
        int length = nums.size();
        if(length == 0){
            return resultRange;
        }
        for(int i = 0;i < length;i++){
            if(nums[i] == target){
                resultRange[0] = i;
                break;
            }
        }

        if(resultRange[0] == -1){
            return resultRange;
        }

        for(int i = length-1;i >= 0;i--){
            if(nums[i] == target){
                resultRange[1] = i;
                break;
            }
        }

        return resultRange;
        
    }
};
```