### 解题思路
核心思路即：当前sum值为正数时添加下一个num才会比num大，也就是有效；
1. 使用一个sum，记录当前的子串和；
2. 判断标准，sum>0情况下才会累加num，否则sum直接替换为num；
3. 每次计算完成后记录一个当前max值，因为在sum值为正数情况下也会减小；
### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //思路：如何和才能最大，前置的数字和为正数，加上下一个数字才会增加，所以：
        int max = nums[0];
        int sum = 0;
        for(int num:nums){
            if(sum > 0) {
                sum +=num;
            } else {
                sum = num;
            }
            max = max > sum ? max : sum ;
            //cout<< "num:" << num << " sum:" << sum << " max:" << max <<endl;
        }
        return max;
    }
};
```