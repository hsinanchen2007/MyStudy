### 解题思路
题目要求判断从起点能不能走到终点。给出了每一个位置能走的最大步数。
假设存在这样一条路径，并且要走N步，那么意味着start  ->  A ->B -> .....   -> end。 每一步都必须同时满足。这是结果返回true的充分必要条件。
那么在计算机中怎么实现呢，计算机代码实现必然要考虑时间上的一致性。倒推确实有着奇效。
定义i ,j 。 i表示当前处理的数，j表示距离i最近的能够走到终点的数，那么只要满足 i+nums[i]>=j ， 不就可以走到终点了吗？
这个不等式是核心，倒推是精髓。
当然你一开始很可能会构造一个有穷状态机，采用回溯的方法进行试探，遇到死胡同退回去。但是这样效果不好。
贪心一般需要想想，一般简单高效的方法往往不是直接能看出来的

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //vector<bool> flag(nums.size(),false);
        int j = nums.size()-1;
        bool flag=true;
        for(int i=j;i>=0;--i){
            if(i+nums[i]>=j){
                flag=true;
                j = i;  // j 必须是距离当前处理数i最近的good数。
            }else flag=false;
        }
        return flag;

    }
};
```