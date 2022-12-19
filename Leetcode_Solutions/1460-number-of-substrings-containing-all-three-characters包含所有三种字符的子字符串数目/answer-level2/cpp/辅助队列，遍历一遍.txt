### 解题思路
这题关键在于子序列数目的计算方式：对每个下标，先找到以该下标开始最短的符合要求的子序列，那么以该下标开始的所有符合要求的子序列数目为以该子序列为前缀的所有子序列数目。接下来就是利用队列找每个这样的子序列，原理类似数组前缀和。
![2020-02-23 10-28-45屏幕截图.png](https://pic.leetcode-cn.com/7a71c0d0065b0f1930034f07891eae330d4eaddd60a936cc907326ae83584e0a-2020-02-23%2010-28-45%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```cpp
class Solution {
public:
    using His = array<int, 3>;
    int numberOfSubstrings(string s) {
        queue<His> q;
        His g{0,0,0};
        q.push(g);
        int res = 0;
        for(int i=0;i<s.size();++i)
        {
            ++g[s[i]-'a'];
            while(!q.empty() && check(q.front(), g))
            {
                q.pop();
                res += (s.size() - i);
            }
            q.push(g);
        }
        return res;
    }

    bool check(const His& i1, const His& i2)
    {
        return i1[0]<i2[0]&&i1[1]<i2[1]&&i1[2]<i2[2];
    }
};
```