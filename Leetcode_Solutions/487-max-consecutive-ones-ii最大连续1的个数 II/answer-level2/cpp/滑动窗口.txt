### 解题思路
用滑动窗口，l为窗口左边界，r为窗口右边界，在窗口中一直保证一直最多一个0存在，然后r-l就是包括这个零的最大长度，最后别忘了对尾巴处理

### 代码

```cpp
class Solution {
public:
//用滑动窗口去做
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0;
        int count_0=0;//统计0的个数
        int max=0;
        for(r=0;r<nums.size();r++){
            if(nums[r]==0){
                if(r-l>max) max=r-l;
                if(count_0>=1){//已经有1个0了
                    while(nums[l]==1) l++;
                    l++;
                }
                else{
                    count_0++;
                }
            }
        }
        if(r-l>max) max=r-l;
        return max;
    }
};
```