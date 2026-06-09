### 解题思路
汉明权重里消最右1的法子用在这里就是dp的状态转移了，从低向上，撞官解#4
ps，%的效率居然比&高。。，但是应该都比/强就是啦

### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        // unordered_map<int> m?
        // base:
        // N == num return
        // iterative: 
        // dp(0) = 0
        // dp(1) = 1
        // if dp(i) % 2 == 1 -> dp(i - 1) + dp(1)
        // else -> dp(i - 1)
        // dp(i - 1) + d(1) -> memo[i-1] && memo[1]
        if (num < 0) return vector<int>();     
        vector<int> v(num + 1, 0);
        for (int i = 0; i <= num; ++i){
            if (i == 0){
                v[i] = 0;
                continue;
            }                    
            // else if (i & 1)
            //     v[i] = v[i - 1] + 1;
            // else 
            //     v[i] = v[i >> 1];                     
            v[i] = v[i & (i - 1)] + 1;
        }
        return v;
    }
};
```