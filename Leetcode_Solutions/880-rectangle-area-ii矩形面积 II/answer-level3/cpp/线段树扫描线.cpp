```
class Solution {
public:
    struct node{
        long long x, y, h;
        int flag;
        node() {};
        node(long long x, long long y, long long h, int flag): x(x), y(y), h(h), flag(flag) {}
        bool operator < (const node &a) const{
            return h < a.h;
        }
    } e[5000];
    
    int cover[50000];
    long long sum[50000];
    int X[50000];
    
    void pushup(int rt, int l, int r) {
        if(cover[rt]) sum[rt] = X[r + 1] - X[l];
        else if(l == r) sum[rt] = 0;
        else sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % 1000000007;
    }
    
    void update(int rt, int l, int r, int x, int y, int v) {
        if(x <= l && r <= y) {
            cover[rt] += v;
            pushup(rt, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        if(x <= mid) update(rt << 1, l, mid, x, y, v);
        if(mid < y) update(rt << 1 | 1, mid + 1, r, x, y, v);
        pushup(rt, l, r);
    }
    
    int rectangleArea(vector<vector<int>>& rectangles) {
        int cnt = 0;
        long long ans = 0;
        memset(cover, 0, sizeof cover);
        memset(sum, 0, sizeof sum);
        memset(X, 0, sizeof X);
        for(int i = 0; i < rectangles.size(); i++) {
            e[cnt] = node(rectangles[i][0], rectangles[i][2], rectangles[i][1], 1);
            X[cnt++] = rectangles[i][0];
            e[cnt] = node(rectangles[i][0], rectangles[i][2], rectangles[i][3], -1);
            X[cnt++] = rectangles[i][2];
        }
        sort(e, e + cnt);
        sort(X, X + cnt);
        //int num = unique(X, X + cnt) - X;
        for(int i = 0; i < cnt; i++) {
            int l = lower_bound(X, X + cnt, e[i].x) - X;
            int r = lower_bound(X, X + cnt, e[i].y) - X - 1;
            update(1, 0, cnt - 1, l, r, e[i].flag);
            long long tem = (e[i + 1].h - e[i].h) * sum[1] % 1000000007;
            ans = (ans + tem) % 1000000007;
        }
        return ans;
    }
};
```
