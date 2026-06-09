### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // 贪心算法 一次遍历，只要今天价格小于明天价格就在今天买入然后明天卖出，时间复杂度O(n)
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // prices.size()得到是一个无符号整型数，如果0-1得到的是一个无符号数会进行极大次数循环，如果要注释这个判断，则需要强转((int)prices.size())-1
        if (prices.size() < 2) return profit;
        for (int i=0; i<prices.size()-1; i++) {
            if (prices[i+1]-prices[i]>0) {
                profit += (prices[i+1]-prices[i]);
            }
        }
        return profit;
    }
};




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    if (prices.size() < 2) return profit;
    for (int i=0; i<prices.size()-1; i++) {
        if (prices[i+1]-prices[i]>0) {
            profit += (prices[i+1]-prices[i]);
        }
    }
    return profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
}




```