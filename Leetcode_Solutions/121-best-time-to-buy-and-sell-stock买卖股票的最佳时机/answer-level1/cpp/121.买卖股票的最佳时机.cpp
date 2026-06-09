### 解题思路
首先分析一下这个序列的特点，要求的值必定是后面的数与前面的数的最大差值。
解题的主要想法是：
从数组头起点两位比较，先求差，如果差值大于当前最大差值max 则更新max
不管最大差值有没有被更新，都要把这两个数中最小的赋值到后面的位置，这样就可以进行下一轮的比较。
12->23->34…….
计算复杂度O(n),空间复杂度O(1)

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)//这个特殊情况要考虑。。不然遇到空集会报错
            return 0;
        int max = 0;
        for(int i = 0; i < prices.size()-1; i++)
            {
                if(prices[i+1] - prices[i] > max)
                    max = prices[i+1] - prices[i];//最大差值更新
                prices[i+1] = (prices[i] < prices[i+1] ? prices[i]:prices[i+1]);
                //两者中小的数放在后面，方便进行下一次比较
            }
        return max;
    }
};
```