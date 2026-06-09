### 解题思路
我看这个题解的时候有个疑问，自己思考的时候也是有个点卡住了，就是
nums[cur]==0时进行cur++，而nums[cur]==2 cur并不+1
等于2时不加1容易理解，因为nums[p2]的值是不确定的，如果等于0,交换回cur，此时cur加1了，回跳过这个0的归类，
但是为什么当 if(nums[cur] == 0) 这个条件的时候，可以cur+1呢，因为nums[p0]不可能等于2，因为如果等于2，就会归类到p2那边去了
，因为cur永远大于等于p0
### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size()-1;
        int cur = 0;
        while(cur <= p2)
        {
            if(nums[cur] == 0)
            {
                swap(nums[cur],nums[p0]);
                p0++;
                //这里之所以cur=cur+1；因为cur >= p0，所以nums[p0]不可能等于2
                //因为下面的elseif nums[cur] == 2 交换到p2去了，所以nums[p0]只能等于1或者0
                cur++; 
            }
            else if(nums[cur] == 2)
            {
                //对比这里 这里并没有cur++，因为这里可能交换后nums[cur]位置可能会是0，如果cur=cur+1了，会跳过这个0的分类
                swap(nums[cur],nums[p2]);
                p2--;
            }
            else
                cur++;

        }
    }
};
```