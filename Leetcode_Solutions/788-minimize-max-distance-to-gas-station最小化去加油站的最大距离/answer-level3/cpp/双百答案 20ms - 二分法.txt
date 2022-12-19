```
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n = stations.size();
        sort(stations.begin(), stations.end());
        double b = stations[0];
        double e = stations[n - 1];
        double l = e - b;
        double exl = l / (n - 1 + K);
        double exh = l / (K + 1);
        double ex = 0;
        while (exh - exl > 1e-6) {
            ex = (exh + exl) / 2;
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                cnt += (stations[i] - stations[i - 1]) / ex;
            }
            if (cnt > K) exl = ex;
            else if (cnt <= K) exh = ex;
        }
        return ex;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```
