### 解题思路
此处撰写解题思路
1.求出极值序列，并标记极大值极小值
2.买入仅为开始点 + 极小值点
3.卖出仅为极大值点 + 结束点
过滤掉大多数的不可能情况。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        if(len == 0 || len == 1) {
            return 0;
        } else if (len == 2) {
            return max (prices[1] - prices[0], 0);
        }

        int ret = 0;
        int * newp = new int [len];
        int * flag = new int [len];
        int count = 0;
        int i = 1;
        int j = 0;

        newp[count] = prices[0];
        flag[count] = 0;
        count++;

        for (i = 1; i < len - 1; i++) {
            if(prices[i] >= prices[i-1] && prices[i] >= prices[i+1]) {
                newp[count] = prices[i];
                flag[count] = 1;
                count++;
            } else if(prices[i] <= prices[i-1] && prices[i] <= prices[i+1]){
                newp[count] = prices[i];
                flag[count] = -1;
                count++;
            }
        }

        newp[count] = prices[i];
        flag[count] = 0;
        count++;

        for(i = 0; i < count - 1; i++) {
            if(flag[i] > 0) {
                continue;
            }

            for (j = i+1; j < count; j++) {
                if(flag[j] < 0) {
                    continue;
                }

                if(newp[j] - newp[i] > ret){
                    ret = newp[j] - newp[i];
                }
            }
        }

        delete [] flag;
        delete [] newp;
        return ret;
    }
};
```