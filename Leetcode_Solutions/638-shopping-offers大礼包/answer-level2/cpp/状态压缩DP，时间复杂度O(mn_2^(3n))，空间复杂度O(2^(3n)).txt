
执行用时 :1324 ms, 在所有 C++ 提交中击败了5.38%的用户
内存消耗 :14.9 MB, 在所有 C++ 提交中击败了47.95%的用户
状态压缩DP，时间复杂度O(mn*2^(3n))，空间复杂度O(2^(3n))
预处理时，将单个商品也作为礼包，然后进行完全背包即可。

class Solution 
{
private:
    long long f[1 << (3 * 6)];

public:
    int shoppingOffers(vector<int>& price,vector<vector<int>>& special,vector<int>& needs) 
    {
        int n = price.size();
        int m = special.size() + n;
        int v = 0;

        for(int i = 0;i < n;i++)
        {
            v |= needs[i] << (3 * i);
        }

        for(int i = 0;i < n;i++)
        {
            auto t = vector<int>(n + 1);
            t[i] = 1;
            t[n] = price[i];
            special.push_back(t);
        }

        f[0] = 0;

        for(int i = 1;i <= v;i++)
        {
            f[i] = INT_MAX;
        }

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j <= v;j++)
            {
                bool flag = true;

                for(int k = 0;k < n;k++)
                {
                    if((((j >> (k * 3)) & 0x07) + special[i][k]) > ((v >> (k * 3)) & 0x07))
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag)
                {
                    int state = 0;

                    for(int k = 0;k < n;k++)
                    {
                        state |= special[i][k] << (3 * k);
                    }

                    f[state + j] = min(f[state + j],f[j] + special[i][n]);
                }
            }
        }

        return f[v];
    }
};