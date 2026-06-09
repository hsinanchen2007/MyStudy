### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector <int> dp ;
        if (n == 1) {
            dp.push_back(0);
            return dp;
        };
        if (n % 2 == 1){
            dp.push_back(0);        
        }
        for (int i=1;i<n ;i=i+2){
                    dp.push_back(i);
                    dp.push_back(-1 * i);
                }
    return dp;
    }
};
```