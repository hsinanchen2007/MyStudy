对于某个点A，判断其是否被另一个点B照亮，等价于判断是否满足以下四个方程：
1. A[0] = B[0];
2. A[1] = B[1];
3. A[0]+A[1] = B[0]+B[1];
4. A[0]-A[1] = B[0]-B[1];
分别用map维护以上四个条件出现的次数。

判断是否某点是否被照明，依次查找四个map即可。

删除某点及周围点时，需要判断点是否已删除：若已删除，则不操作；否则，对四个map的计数减一。


```
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<map<int, int>> m(4);
        set<vector<int>> exists(lamps.begin(), lamps.end());
        for(auto v: lamps) {
            m[0][v[0]]++;
            m[1][v[1]]++;
            m[2][v[0]-v[1]]++;
            m[3][v[0]+v[1]]++;
        }
        vector<int> res;
        for(auto v: queries) {
            res.push_back(light(m, v[0], v[1]));
            if(res.back()==0) continue;
            for(int i=-1;i<=1;i++) {
                for(int j=-1;j<=1;j++) {
                    vector<int> tmp = {v[0]+i,v[1]+j};
                    if(exists.count(tmp)) {
                        turndown(m, N, tmp[0], tmp[1]);
                        exists.erase(tmp);
                    }
                }
            }
        }
        return res;
    }
    bool light(vector<map<int, int>>& m, int x, int y) {
        return (m[0].find(x)!=m[0].end() && m[0][x]>0) 
            || (m[1].find(y)!=m[1].end() && m[1][y]>0)
            || (m[2].find(x-y)!=m[2].end() && m[2][x-y]>0)
            || (m[3].find(x+y)!=m[3].end() && m[3][x+y]>0);
        // return m[0][x]>0 || m[1][y]>0 || m[2][x-y]>0 || m[3][x+y]>0;
    }
    void turndown(vector<map<int, int>>& m, int N, int x, int y) {
        if(m[0].find(x)!=m[0].end() && m[0][x]>0) m[0][x]--;
        if(m[1].find(y)!=m[1].end() && m[1][y]>0) m[1][y]--;
        if(m[2].find(x-y)!=m[2].end() && m[2][x-y]>0) m[2][x-y]--;
        if(m[3].find(x+y)!=m[3].end() && m[3][x+y]>0) m[3][x+y]--;
    }
};
```
