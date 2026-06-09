### 解题思路
1. 读懂本题题意是：把筹码的位置放在了chip数组。
2. 值得注意的是，**一个**无论是处在奇数位置的筹码移动到偶数位置，还是从偶数位置移动到奇数位置，消耗都是**1**
3. 那么只要分别统计处在奇数位置的筹码的数量和处在偶数位置的筹码的数量
4. 将数量少的移动到数量多的位置，即可使移动代价最少

### 代码

```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int cnt_odd = 0, cnt_even = 0;
        for(int i = 0; i < chips.size(); i++)
            if(chips[i] % 2 == 0) cnt_even ++;
            else cnt_odd ++;
        return min(cnt_odd, cnt_even);
    }
};
```