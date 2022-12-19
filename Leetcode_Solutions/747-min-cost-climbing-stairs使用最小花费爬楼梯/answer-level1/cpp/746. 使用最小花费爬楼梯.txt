### 解题思路
。。。。讲真感觉这种题没什么意思，为了考DP而设置了一个并不合理的背景，光是理解题意就挺麻烦。。。
硬头皮解释一下，这个和之前有道问有多少种上楼方式还是有点区别的。70题。
【70题】我只要统计有多少种走的方式，第n级一定是n-1和n-2级的方式数之和。。。
【本题】到第n级总共最少走多少，应该是第n-1和n-2累计的耗费精力中少的那个加上本级。。。
啊啊啊啊啊啊啊好烦啊哼

### 代码
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a1=cost[0];
        int a2=cost[1];
        int temp;
        for (int i=2;i<cost.size();i++){
            temp=min(a1,a2)+cost[i];
            a1=a2;
            a2=temp;
        }
        return min(a1,a2);
    }
};
```