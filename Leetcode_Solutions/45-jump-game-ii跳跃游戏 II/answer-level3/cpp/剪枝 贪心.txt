### 解题思路
最开始想到的是广搜加打表，但是还是显示超时，后来想应该是打表的剪枝力度不够，于是想到能不能每次都明确的去确定下一步，想到flag当前位置，然后预设走i步到达m位置，那么去取m+numsm[m]的最大值不就是下次能到达的最远值吗（前提要判断这个值是小于终点值的），那么这个问题就转变成了类似贪心（我也不知道是贪心还是动规）的问题解决了。

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int boot,flag;
        boot = flag = 0;
        if(nums.empty()) return 0;
        while(flag<nums.size()-1){
            if(flag+nums[flag]>=nums.size()-1){
                boot++;
                return boot;
            }
            int maxnum = 0 ;
            int path;
            for(int i=0; i<=nums[flag];i++){
                if(nums[i+flag]+flag+i>maxnum){
                   maxnum = nums[i+flag]+flag+i;
                   path = flag+i;}
            }
            flag = path;
            boot++;

        }
        return boot;
    }
};
```