1. i从倒数第二个开始数
2. 当nums[i]为0的时候，j = i - 1
    1. 当nums[j] <= (i - j)的时候j--;
    2. 判断j是否小于0
        1. 小于0则为false
        2. 大于0则 i = j

```
class Solution {
public:
    bool canJump(vector<int>& nums) {
         int flag = true;
        int j;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] != 0)
                continue;
            j = i - 1;
            flag = false;
            while(j >= 0 && nums[j] <= (i - j)) j--;
            if(j < 0)
                break;
            else{
                flag = true;
                i = j;
            }
        }

        return flag;
    }
};
```
