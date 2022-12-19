将x轴按照每个矩形的两个横坐标切分成若干小块，每个小块中对y轴从下到上（或从上到下）扫描，依次计算每个小区域的面积即可。
```
#define ll long long


struct horedge{
    ll value;
    int left;
    int right;
    int type;  // 0: in; 1: out
    horedge(int v=0, int l=0, int r=0, int t=0): value(v), left(l), right(r), type(t) {}
};


struct CMP{
    bool operator()(const horedge &a, const horedge &b) const{
        return a.value < b.value || (a.value == b.value && a.type > b.type);
    }
};


class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<int> xs(2 * n);
        vector<horedge> edges(2 * n);
        int i;
        for (i = 0; i < n; ++i){
            xs[2 * i] = rectangles[i][0];
            xs[2 * i + 1] = rectangles[i][2];
        }
        sort(xs.begin(), xs.end());

        for (i = 0; i < n; ++i){
            edges[2 * i] = horedge(rectangles[i][1], rectangles[i][0], rectangles[i][2], 0);
            edges[2 * i + 1] = horedge(rectangles[i][3], rectangles[i][0], rectangles[i][2], 1);
        }
        sort(edges.begin(), edges.end(), CMP());

        ll ans = 0;
        ll lastvalue = 0;
        int flag = 0;
        int j;
        for (i = 0; i < 2 * n - 1; ++i){
            for (j = 0; j < 2 * n; ++j){
                if (!(edges[j].left <= xs[i] && xs[i + 1] <= edges[j].right)) continue;

                ans += (edges[j].value - lastvalue) * (xs[i + 1] - xs[i]) * (flag > 0);
                lastvalue = edges[j].value;
                if (edges[j].type == 0) ++flag;
                else --flag;
            }
        }
        return ans % (1000000007);
    }
};
```
