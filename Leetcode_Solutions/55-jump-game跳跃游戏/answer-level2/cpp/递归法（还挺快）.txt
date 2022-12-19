### 解题思路
万能递归！！
这道题从左到右不好做，从右到左就很简单了，我们要判断从0能不能到size-1,那我们只需要从0到size-2这size-1个数里找到一个数作为跳板。
以[2, 3, 1, 1, 4]为例，从index_0跳到index_4,我们可以从后往前遍历。
先看index_3,我们可以通过index_3和index_4的值判断能否从index_3到index_4，
    1.如果能，那我们就需要判断能否从index_0到index_3，这个问题是题目开始定义的问题（能否从index_0到index_3)的子问题。
    2.如果不能，则我们将index往前移动，看index_2能否到index_4，如此循环。

### 代码

```cpp
class Solution {
public:
    bool subCanJump(vector<int>& nums, int i){
        if(i==0)
            return true;
        int j=i-1;
        while(j>=0){
            if(nums[j]>=i-j)
                return subCanJump(nums, j);
            j--;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
         return subCanJump(nums, nums.size()-1);
    }
};
```