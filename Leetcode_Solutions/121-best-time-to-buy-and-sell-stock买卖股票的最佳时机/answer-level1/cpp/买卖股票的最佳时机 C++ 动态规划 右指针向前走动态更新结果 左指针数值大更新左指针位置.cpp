### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    
    // // 暴力解答
    // int maxProfit(vector<int>& prices) {
    //     int max = 0;
    //     // 卖出值从右往左检索
    //     for (int i=prices.size()-1; i>-1; i--) {
    //         // 买入值从左往右检索，且必须先买入后卖出
    //         for (int j=0;j<i;j++) {
    //             if (prices[i]-prices[j] > max) {
    //                 max = prices[i]-prices[j];
    //             }
    //         }
    //     }
    //     return max;
    // }
    
    // 双指针法动态规划 
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int res = 0, left = 0, right = 1;
        // 右指针一直往前走
        while (right < prices.size()) {
            // 如果左指针对应的数大于右指针，就把左指针移到当前右指针所在的位置
            if (prices[left] > prices[right]) {
                left = right;
            }
            // 如果左指针对应的数小于右指针对应的数，就更新结果
            else if (prices[left] < prices[right]) {
                // 差值大于res，更新res结果，否则保持res
                res = (prices[right] - prices[left]) > res ? (prices[right] - prices[left]) : res;
            }
            right++;
        }
        return res;
    }
};


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size()<2) return 0;
    int res = 0, left = 0, right = 1;
    while (right < prices.size()) {
        if (prices[left] > prices[right]) {
            left = right;
        }
        else if (prices[left] < prices[right]) {
            res = (prices[right] - prices[left]) > res ? (prices[right] - prices[left]) : res;
        }
        right++;
    }
    return res;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
}



```