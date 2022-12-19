### 解题思路
首先，我们要明确一点，在本题中登顶是走到数组之外而不是走到最后一个元素。明确这一点之后再来做这道题就很简单了，因为每次可以走一步或两不，一次当我们走到nums[i]时我们需要知道它是从从s[i-1]走来的还是从s[i-2]走来的即谁小就是从谁走来的，在这里我们设置两个变量pre,current来记录到达s[i-1]走过的距离，以及到达s[i-2]走过的距离。
注意，在退出循环的时候，我们要返回min(pre,current)因为走到数组结尾，还要走一步。
### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int pre=0;
       int current=0;
       for(int i=0;i<cost.size();i++)
       {
           int temp=current;
           if(current>pre)
           {
               current=pre+cost[i];
           }
           else
           {
               current+=cost[i];
           }
           pre=temp;
       }
       return min(pre,current);
    }
};
```