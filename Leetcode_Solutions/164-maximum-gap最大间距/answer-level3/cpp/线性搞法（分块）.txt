题目说数据范围在int内，于是我们可以设N=2^16,弄N个大小为N的块。
分2种情况讨论：
1.当a[i] / N == a[j] / N（2个数在同一个块）时，ans=max(ans, a[i] - a[j]);
对此我们只要对于所有的y = a[i] % N，存上对应的x = a[i] / N
从0~N枚举y，然后维护pre_y[x]
ans = max(ans, y - pre_y[x])

2.当a[i] / N < a[j] / N时，ans=max(ans,(j - i) * N + a[j] % N - a[i] % N);
我们只要对每个块存它的最大值和最小值
ans = max(ans, (j - i) * N + mi[j] - mx[i]);

时间复杂度O(n + N)
```
const int N = 1 << 16;

class Solution {
public:
    int mx[N + 5], mi[N + 5], pre[N + 5];
    vector<int> ver[N + 5];
    int maximumGap(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < N; i++) mx[i] = -1, mi[i] = N, pre[i] = -1, ver[i].clear();
        for(int i = 0; i < n; i++) {
            int x = a[i] / N, y = a[i] % N;
            mx[x] = max(mx[x], y);
            mi[x] = min(mi[x], y);
            ver[y].push_back(x);
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int &x : ver[i]) {
                if(pre[x] != -1) ans = max(ans, i - pre[x]);
                pre[x] = i;
            }
        }
        int prex = -1, prey = -1;
        for(int i = 0; i < N; i++) {
            if(mi[i] < N && prex != -1) {
                ans = max(ans, (i - prex) * N + mi[i] - prey);
            }
            if(mx[i] > -1) {
                prex = i;
                prey = mx[i];
            }
        }
        return ans;
    }
};
```
