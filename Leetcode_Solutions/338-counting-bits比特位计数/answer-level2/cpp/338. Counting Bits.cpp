### 解题思路
移位操作统计

### 代码

```
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i = 0; i <= num; i++){
            int u = i;
            int count = 0;
            for( ; u != 0; u >>= 1){
                count += u & 1;
            }
            ret.push_back(count);
        }
        return ret;
    }
};
```



### 解题思路
DP, bit位上面找规律

### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        vector<int> dp(num + 1, 0);
        dp[0] = 0;
        ret.push_back(0);
        for(int i = 1; i <= num; i++){
            dp[i] = dp[i/2] + i%2;
            ret.push_back(dp[i]);
        }
        return ret;
    }
};
```