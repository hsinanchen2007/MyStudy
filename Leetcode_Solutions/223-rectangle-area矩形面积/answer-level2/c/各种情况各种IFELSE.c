### 解题思路
1. 两个矩形没有相交，返回两个面积和
2. ABCD完全包含EFGH，返回ABCD面积
3. EFGH完全包含ABCD，返回EFGH面积
4. 求出相交部分的高、宽，减去相交面积

### 代码

```c
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    int area1=(C-A)*(D-B);
    int area2=(E-G)*(F-H);

    if (C<=E || G<=A || H<=B || D<=F) {
        return area1+area2;
    }

    if (A<=E && G<=C && D>=H && F>=B) {
        return area1;
    }

    if (E<=A && C<=G && H>=D && B>=F) {
        return area2;
    }

    int w=0;
    int h=0;
    if (A<=E && E<C && C<G) {
        w=C-E;
    } else if (A<=E && G<=C) {
        w=G-E;
    } else if (E<=A && A<G && C>G) {
        w=G-A;
    } else if (E<=A && C<=G) {
        w=C-A;
    }

    if (D>=H && H>B && B>F) {
        h=H-B;
    } else if (D>=H && F>=B) {
        h=H-F;
    } else if (H>=D && D>F && F>B) {
        h=D-F;
    } else if (H>=D && B>=F) {
        h=D-B;
    }

    return area1+area2-h*w;

}
```