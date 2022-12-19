### 解题思路
方法一：常规方法，初始化一个三维数组，空间占用较大
方法二：空间占用为常数
### 代码
方法一
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0)
            return 0;
        int k = (size+2)/3;
        int profit[size][k+1][2];
        for (int i=0; i<size; i++) {
            profit[i][0][0] = 0;
            for (int j=1; j<=k; j++) {
                if (i==0) {
                    profit[i][j][0] = 0;
                    profit[i][j][1] = -prices[i];
                    continue;
                }
                if (i==1) {
                    profit[i][j][0] = max( profit[i-1][j][0], profit[i-1][j][1]+prices[i] );
                    profit[i][j][1] = max( profit[i-1][j][1], -prices[i] );
                    continue;
                }
                profit[i][j][0] = max( profit[i-1][j][0], profit[i-1][j][1]+prices[i] );
                profit[i][j][1] = max( profit[i-1][j][1], profit[i-2][j-1][0]-prices[i] );
            }
        }
        return profit[size-1][k][0];
    }
};
```
方法二
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int p_i_0 = 0, //i==-1,initialize
            p_i_1 = INT_MIN,
            p_i2_0 = 0; //p[i-2][0]
        for (int i:prices) {
            int temp = p_i_0;
            p_i_0 = max( p_i_0, p_i_1+i );
            p_i_1 = max( p_i_1, p_i2_0-i );
            p_i2_0 = temp;
        }
        return p_i_0;
    }
};
```
