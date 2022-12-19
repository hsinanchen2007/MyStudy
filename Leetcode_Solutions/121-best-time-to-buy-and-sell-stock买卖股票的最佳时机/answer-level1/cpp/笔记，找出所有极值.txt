### 解题思路
此处撰写解题思路
1. 找出所有极值
2. 以极值作为基本点进行查找最大收益
3. 时间复杂度 N2 ， 空间复杂度 N
4. 查找方式可能其他的方法更快

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
        int count = 0;
        int i = 1;
        int j = 0;

        newp[count] = prices[0];
        count++;

        for (i = 1; i < len - 1; i++) {
            if(prices[i] >= prices[i-1] && prices[i] >= prices[i+1]) {
                newp[count] = prices[i];
                count++;
            } else if(prices[i] <= prices[i-1] && prices[i] <= prices[i+1]){
                newp[count] = prices[i];
                count++;
            }
        }

        newp[count] = prices[i];
        count++;

        for(i = 0; i < count - 1; i++) {
            for (j = i+1; j < count; j++) {
                if(newp[j] - newp[i] > ret){
                    ret = newp[j] - newp[i];
                }
            }
        }

        delete [] newp;
        return ret;
    }
};
```