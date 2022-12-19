### 解题思路
1.如果没有0存在，则一定能到达最后一个点
2.从后往前遍历，如果有0存在于i点，则要看前面的点before能否跨越这个点：
  nums[before]>zerolocation - before
注意两种特殊情况：
(a)最后一个点只需要被到达，所以最后一个点为0是可以接受的，那么我们要从lenth-2开始从后往前遍历，否则影响上面的判断。
(2)注意多个0的情况，如果前一个遇到的0没有被跨越，则后面的点都要判断能否跨越最前面遇到的那个0点
### 代码

```cpp
#include<algorithm>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if( len == 1 || find(nums.begin(),nums.end(),0) == nums.end())return true;
        else{
            bool crosszero = true;
            int zerolocation = -1;
            for(int i = len-2 ; i >= 0 ; i--){
                if (nums[i] == 0 && crosszero == true){
                    zerolocation = i;
                    crosszero = false;
                }
                if (nums[i]>zerolocation - i )crosszero = true;

            }
            return crosszero;
        }
         
    }
};
```