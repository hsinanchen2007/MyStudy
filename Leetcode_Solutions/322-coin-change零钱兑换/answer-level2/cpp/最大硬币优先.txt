### 解题思路
1.核心思想：将数组进行排序，先尽量用更多最大的，然后依次将最大硬币的数量减少再试，然后再从第二大的开始试。
2.最先找到的不一定是最优解，比如[1, 7, 10]，14，那么最先找到的就是10+1+1+1+1，但是7+7才是最优的，因此需要把每种情况都找完。
3.如果数组当前的最大值比剩下的amount还要大，那么没必要将数组右边的数纳入组合，直接缩小数组范围，直到范围中所有的数都<=amount，这样可以减少递归次数。
4.如果当前最大硬币的数量加上外层更大的硬币的数量已经>=best了，那就没必要再递归下去了，因为如果减少当前硬币数量的话，那么一定需要更多的小硬币，硬币数量就更多了。

参考：[ikaruga的题解](https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/)

### 代码

```cpp
class Solution {
private:
    int best;
    void Change(vector<int>& coins, int edgeIdx, int amount, int prevCount){
        if(amount == 0) {
            if(prevCount<best) best = prevCount;
            return;
        }
        if(edgeIdx<0 || coins[0]>amount) return;

        while(edgeIdx>=0 && coins[edgeIdx]>amount) edgeIdx--;
        if(edgeIdx < 0) return;

        int count = amount/coins[edgeIdx];
        if(count+prevCount>=best) return;
        for(; count>=0; count--){
            Change(coins, edgeIdx-1, amount-count*coins[edgeIdx], count+prevCount);
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        best = 0x7FFFFFFF;
        sort(coins.begin(), coins.end(), less<int>()); // 从小到大排序
        Change(coins, coins.size()-1, amount, 0);
        return (best<0x7FFFFFFF) ? best:-1;
    }
};
```