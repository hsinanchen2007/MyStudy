### 解题思路
暴力求解，先建立x,y坐标系，把所有的矩阵在坐标系中进行Paint，Paint一次加一。最后统计是否所有有效坐标系中的值都为1.
Ps：最好少用C++ STL库，否则性能不过关。

### 代码

```cpp
class Solution {
public:
    unordered_map<long long, int> um;
    unordered_map<int, int> idx;
    unordered_map<int, int> idy;

    bool isRectangleCover(vector<vector<int>>& rectangles) 
    {
        set<int> xr;
        set<int> yr;

        // 生成x, y 栅格坐标
        for(auto i = 0; i < rectangles.size(); i++) {
            vector<int> & a = rectangles[i];
            xr.insert(a[0]);
            xr.insert(a[2]);
            yr.insert(a[1]);
            yr.insert(a[3]);
        }        
        // 生成x,y坐标的index
        int cntx = 0;
        for(auto it = xr.begin(); it != xr.end(); it++) {
            idx[*it] = cntx++;
        }
        int cnty = 0;
        for(auto it = yr.begin(); it != yr.end(); it++) {
            idy[*it] = cnty++;
        }
        cntx--;
        cnty--;
        char *p = new char[cntx*cnty];
        memset(p, 0, cntx*cnty);

        for(auto a: rectangles) {
            int x0 = idx[a[0]];
            int y0 = idy[a[1]];
            int x1 = idx[a[2]];
            int y1 = idy[a[3]];
            for(int y = y0; y < y1; y++) {
                char *tpa = p + y * cntx + x0;
                char *tpb = p + y * cntx + x1;
                while(tpa < tpb) {
                    *tpa += 1;
                    tpa++;
                }
            }
        }
        int i = 0;
        while(i<cntx*cnty) {
            if(p[i] != 1) {
                delete [] p;
                return false;
            }
            i++;
        }
        delete [] p;
        return true;
    }
};
```