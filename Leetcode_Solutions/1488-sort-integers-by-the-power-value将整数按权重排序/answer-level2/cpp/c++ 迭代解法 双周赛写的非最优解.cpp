### 解题思路
对于每一个数字我们都可以通过循环不断采用题中的变换规则变成1并得到相应的步数。但如果从lo到hi每个数都算一遍很明显就会有浪费的地方。
我们在计算的过程里把每个值的步数记录一下，避免重复计算。

一个失误的地方在于当时没想清楚应该把每个中间过程都记录一下，而不是只记录lo到hi的每一个值的步数。那样确实应该用递归的写法，迭代有些难处理。

具体参考代码即可。

真诚欢迎大家关注我的github和leetcode仓库～
[我的github](https://www.github.com/wfnuser)
[我的题解](https://www.github.com/wfnuser/leetcode)
最近沉迷刷题 同时也在学习和实现lua，欢迎交流

### 代码

```cpp
class Solution {
public:
    unordered_map<int, int> weight;
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> V;
        for (int i = lo; i <= hi; i++) {
            int step = 0;
            int cur = i;
            while (cur != 1) {
                if (weight[cur]) {
                    step += weight[cur];
                    break;
                } else {
                    step++;
                    if (cur % 2 == 0) {
                        cur = cur / 2;
                    } else {
                        cur = 3*cur + 1;
                    }
                }
            }
            weight[i] = step;
            V.push_back(make_pair(step, i));
        }
        
        sort(V.begin(), V.end());
        
        return V[k-1].second;
    }
};
```