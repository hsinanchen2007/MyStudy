### 解题思路
![TI)ELU\[4EK\]B{V{TVJ0QJ(0.png](https://pic.leetcode-cn.com/166058598e4691576a671f8b9727dffc2a8f208327e06d65256aa03aefb64c52-TI\)ELU%5B4EK%5DB%7BV%7BTVJ0QJ\(0.png)

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size=cost.size(),one=0,two=0;
        /*dp思路是i阶梯的花费f[i] = cost[i] + min(f[i-1], f[i-2]),one是i的前一个阶梯，two是i的前两个阶梯*/
        for(int i=0;i<size;i++)
        {
            int cur=cost[i]+(one<=two?one:two);
            two=one;
            one=cur;
        }
        //这里返回两个最小值是因为，最后一个和倒数第二个阶梯都可以直接到达楼顶，因此返回最小值
        return min(one,two);
    }
};
```