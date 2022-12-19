```
a -> e           0 -> 1
e -> a i         1 -> 0 2
i -> a e o u     2 -> 0 1 3 4
o -> i u         3 -> 2 4
u -> a           4 -> 0
```


```
class Solution {
public:
    int countVowelPermutation(const int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1,
            na = 1, ne = 1, ni = 1, no = 1, nu = 1;
        for (int j = 1; j < n; j++) {
            na = avoid(avoid(e, i), u);
            ne = avoid(a, i);
            ni = avoid(e, o);
            no = i;
            nu = avoid(i, o);
            a = na, e = ne, i = ni, o = no, u = nu;
        }
        return avoid(avoid(avoid(avoid(a, e), i), o), u);
    }

private:
    static inline int avoid(const int a, const int b) {
        return (a + b)%1000000007;
    }
};
```
