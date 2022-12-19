### 解题思路
1.判断是否重叠
2.计算重叠区域的面积，采用投影到两个坐标轴上

### 代码

```cpp
class Solution {
public:
    bool overlap(int &A, int &B, int &C, int &D, int &E, int &F, int &G, int &H){
        return !(G<=A || 
                F>=D || 
                E>=C ||
                H<=B);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area1 = (C-A)*(D-B);
        long long area2 = (G-E)*(H-F);
        if(overlap(A,B,C,D,E,F,G,H)){
            vector<int> w = {A,C,E,G};
            vector<int> h = {B,D,F,H};
            sort(w.begin(), w.end());
            sort(h.begin(), h.end());

            return area1+area2-(w[2]-w[1])*(h[2]-h[1]);
        }
        else return area1+area2;
    }
};
```