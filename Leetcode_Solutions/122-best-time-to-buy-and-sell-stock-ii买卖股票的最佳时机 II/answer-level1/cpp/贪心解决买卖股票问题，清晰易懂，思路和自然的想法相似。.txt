### 解题思路
此处撰写解题思路
思路的话是我自己想的，要严格说算法的话是贪心，按照题目意思，及时在最低的时候买入，只要这以后，只要价格要下降就将这笔卖出，贪心地避免一切损失从而得到最大的收益。具体的做法是做一个代表趋势的矩阵用1 0标记每一天相比后一天的增减趋势，最后一天比较前一天。然后开始循环，模拟咱们之前的思路，1的时候买入0的时候卖出就可以了。复杂度是O(n)

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        vector<bool>tend(prices.size()-1);
        for(int i = 0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i])
                tend[i] = 1;//未来会上升
            else
                tend[i] = 0;//未来会下降
        }
        tend[prices.size()-1] = prices[prices.size()-1]>prices[prices.size()-2]?1:0;
        int res = 0;
        int buy,sell;
        buy = sell = 0;
        for(int i = 0;i<tend.size();i++){
            if(tend[i] == 1){
                buy = i;
                while(i<tend.size()){
                    if(tend[i] == 0)
                        break;
                    i++;
                }
                sell = i;
                res += prices[sell]-prices[buy]; 
            }
        }
        return res;
    }
};
```