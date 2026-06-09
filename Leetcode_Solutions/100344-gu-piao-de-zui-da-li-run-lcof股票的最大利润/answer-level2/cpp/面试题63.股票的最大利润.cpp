### 解题思路
- 核心要点：一次遍历，记录minval和当前遍历价格与minval差值的最大值maxval，maxval即为结果
- 执行用时：12 ms, 在所有 C++ 提交中击败了46.29%的用户
- 内存消耗：12.8 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval=1e9,maxval=0;
        for(int price:prices){
            maxval=max(maxval,price-minval);
            minval=min(minval,price);
        }
        return maxval;
    }
};
```