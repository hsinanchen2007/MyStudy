### 解题思路
1. 非常明确的是，第i位的值为前`i-1`位的累积再乘以后`n-i`位的累积
2. 先从左到右累积，第`i`位的值位前`i-1`位的累积
3. 再从右到左累积，第`i`位的值为`2.`的结果乘上后`n-i`位的累积


### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int>  ans(n);
        int tmp = 1;
        for(int i = 0; i < a.size(); ++i){
            ans[i] = tmp;
            tmp *= a[i];
        }
        tmp = 1;
        for(int i = n-1; i >= 0; --i){
            ans[i] *= tmp;
            tmp *= a[i];
        }
        return ans;
    }
};
```