### 解题思路
实际上是用带负数的x进制表示target。

### 代码

```cpp
typedef long long ll;
const ll INF = 1e10;

class Solution {
    ll ans = INF;
    unordered_map<string, ll> memo;
    vector<ll> cost, fac;
    string encode(ll a, ll b) {
        return to_string(a) + "#" + to_string(b);
    }
    
    ll solve(ll target, int limit) {
        string code = encode(target, limit);
        if (memo.find(code) != memo.end())
            return memo[code];
        if (target == 0)
            return 0;
        ll sum = 0;
        ll num = target / fac[limit];
        if (num * cost[limit] >= ans)
            return INF;
        if (limit == 0)
            return num * cost[limit];
        ll left = num * cost[limit] + solve(target - fac[limit] * num, limit - 1);
        ll right = (num + 1) * cost[limit] + solve(fac[limit] * (num + 1) - target, limit - 1);
        return memo[code] = min(left, right);
    }
public:
    int leastOpsExpressTarget(int x, int target) {
        cost.assign(30, 0);
        cost[0] = 2;
        for (int i = 1; i < 30; ++i)
            cost[i] = i;
        fac = {1};
        for (int i = 1; fac.back() < INF; ++i)
            fac.emplace_back(fac.back() * x);
        int limit = 0;
        while (target > fac[limit])
            limit++;
        for (int i = limit; i >= 0; --i)
            ans = min(ans, solve(target, i));
        return ans - 1;
    }
};
```