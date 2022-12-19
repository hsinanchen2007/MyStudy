### C++  $O(n \log N)$解法




用树状数组，不过这个题的数据范围很小也没必要，但是刚学的东西用到了还是很开心的！！

![Snipaste_2020-03-29_12-55-52.png](https://pic.leetcode-cn.com/c2560d6d4379b446788ca1a22036f03e5c15d7415f9d29d54c084db103669995-Snipaste_2020-03-29_12-55-52.png)


### c++代码
```cpp
class Solution {
public:
    
    const static int N = 1e5 + 10;
    
    int tr[N], tr1[N];
    int b1[N], s1[N];
    int b2[N], s2[N];
    
    int lowbit(int x)
    {
        return x & -x;
    }
    
    void add(int x, int c)
    {
        for (int i = x; i <= 1e5; i += lowbit(i))
            tr[i] += c;
    }
    
    int query(int x)
    {
        int res = 0;
        for (int i = x; i >= 1; i -= lowbit(i))
            res += tr[i];
        return res;
    }
    
    void add1(int x, int c)
    {
        for (int i = x; i <= 1e5; i += lowbit(i))
            tr1[i] += c;
    }
    
    int query1(int x)
    {
        int res = 0;
        for (int i = x; i >= 1; i -= lowbit(i))
            res += tr1[i];
        return res;
    }
    
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        if (n <= 2) return 0;
        else
        {
            add(rating[0], 1);
            for (int i = 1; i < n - 1; i++)
            {
                s1[i] = query(rating[i] - 1);
                b1[i] = query(1e5) - query(rating[i]);
                add(rating[i], 1);
            }
            add(rating[n - 1], 1);
            for (int i = n - 1; i >= 1; i--)
            {
                s2[i] = query1(rating[i] - 1);
                b2[i] = query1(1e5) - query1(rating[i]);
                add1(rating[i], 1); 
            }
            
            for (int i = 1; i < n - 1; i++)
            {
                res += s1[i] * b2[i];
                res += b1[i] * s2[i];
            }
        }
        return res;
    }
};
```
