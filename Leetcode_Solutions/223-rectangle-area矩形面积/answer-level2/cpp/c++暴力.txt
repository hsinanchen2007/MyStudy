### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long res=0;
        if(A>=G || B>=H || C<=E || D<=F){}
        else{
            res-=(max(min(C,G)-max(A,E),0))*(max(min(D,H)-max(B,F),0));
        }
        res+=(long long)(C-A)*(D-B)+(long long)(G-E)*(H-F);
        return res;
    }
};
```