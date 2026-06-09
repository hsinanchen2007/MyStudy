对于矩形，在已知三个点的情况下，求第四个点的方法如下：
1. 先根据边的长度找到已经连成对角线上的两个点pi, pj, 以及即将与第四个点连成对角线的店pk;
2. 根据对称性求出第四个点的坐标，x = pi.x + pj.x - pk.x, y = pi.y + pj.y - pk.y;
3. 根据边的长度校验这四个点是否组成矩形。

```
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        if(n<4) return 0;
        map<int, set<int>> m;
        for(auto p: points) m[p[0]].insert(p[1]);
        double res = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    auto p = match(points, i, j, k);
                    if(m.find(p.first[0]) != m.end() && m[p.first[0]].count(p.first[1])) {
                        if(res<=0 || res>p.second) res = p.second;
                    }
                }
            }
        }
        return res;
    }
    // 找到对角线点，第四个点的坐标，并返回矩形面积
    pair<vector<int>, double> match(vector<vector<int>>& p, int i, int j, int k) {
        long dij2 = distance2(p[i], p[j]);
        long dik2 = distance2(p[i], p[k]);
        long djk2 = distance2(p[j], p[k]);
        if(dij2+dik2==djk2) return revert(p, j, k, i);
        if(dij2+djk2==dik2) return revert(p, k, i, j);
        if(dik2+djk2==dij2) return revert(p, i, j, k);
        return {{-1, -1}, 0};
    }
    // 计算距离的平方
    long distance2(vector<int>& p1, vector<int>& p2) {
        long x = p1[0]-p2[0];
        long y = p1[1]-p2[1];
        return x*x + y*y;
    }
    // 找到对角点，校验矩形，返回坐标及矩形面积
    pair<vector<int>, double> revert(vector<vector<int>>& p, int i, int j, int k) {
        // 找对角点
        vector<int> res = {p[i][0]+p[j][0]-p[k][0], p[i][1]+p[j][1]-p[k][1]};
        // 校验是否是矩形
        long dik = distance2(p[i], p[k]);
        long djk = distance2(p[j], p[k]);
        long dip = distance2(p[i], res);
        long djp = distance2(p[j], res);
        // cout<<dik<<" "<<djk<<" "<<dip<<" "<<djp<<" "<<i<<j<<k<<res[0]<<" "<<res[1]<<endl;
        if(dik==djp && djk==dip) {
            return {res, sqrt(double(dik*djk))};
        } else {
            return {{-1, -1}, 0};
        }
    }
};
```
