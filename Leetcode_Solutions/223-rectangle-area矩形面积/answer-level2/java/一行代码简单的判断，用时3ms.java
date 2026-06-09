```
public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C-A)*(D-B)+(G-E)*(H-F)-((E<C && A<G && F<D && B<H )?0:(Math.min(C,G)-Math.max(E,A))*(Math.min(H,D)-Math.max(B,F)));
    }
```