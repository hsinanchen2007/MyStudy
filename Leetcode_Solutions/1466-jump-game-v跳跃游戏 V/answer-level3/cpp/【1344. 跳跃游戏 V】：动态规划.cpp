#### 解题思路

通过题目，我们要明白的一点就是，只能往低处跳。那么某一点`i`可以跳到的点的个数，只和该点左边`[i-d, i-1]`以及右边`[i+1, i+d]`比`i`位置低的点有关。

因此，动态规划的状态转移很显然就是由低位置向高位置转移。

例如，某一点`i`可以到达点的个数`dp[i] = 1 + max(max(dp[i-d]...dp[i-1]), max(dp[i+1, i+d]));`，同时排除其中位置高于`i`的点。

```cpp
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) { 
        return a.first < b.first;
    }
    int maxJumps(vector<int>& arr, int d) {
        vector<pair<int, int>> bind;
        int len = arr.size();
        for (int i = 0; i < len; i++) {
            bind.push_back(pair(arr[i], i));
        }
        sort(bind.begin(), bind.end(), cmp);
        int ret = 0, dp[1001];
        for (int i = 0; i < len; i++) {
            int h = bind[i].first, pos = bind[i].second;
            dp[pos] = 1;
            for (int j = pos-1; j >= pos-d && j >= 0 && arr[j] < h; j--) {
                dp[pos] = max(dp[pos], 1+dp[j]);
            }
            for (int j = pos+1; j <= pos+d && j < len && arr[j] < h; j++) {
                dp[pos] = max(dp[pos], 1+dp[j]);
            }            
            ret = max(ret, dp[pos]);
        }
        return ret;
    }
};
```



#### 解释

这里使用了数据结构`pair`用来绑定值和索引，使得排序之后`arr`中的值和索引仍能对应。

`pair`是常用来绑定值和索引的数据结构，使用也很简单。对`pair`不熟悉的同学，可以[点我](http://www.cplusplus.com/reference/utility/pair/)阅读官方文档。



#### 最后

感谢您的阅读！

欢迎大家留言，一起讨论交流。