```
class Solution {
public:
    int numWays(int n, int k) {
        if(n==0 || k==0) return 0;
        // a: 以一个相同数字结尾, b: 以两个相同数字结尾
        int a = k, b = 0, c;
        for(int i=1;i<n;i++) {
            c = a;
            // 在确定当前最后一个数字的情况下，下一个数字有k-1种可能
            a = (a+b)*(k-1);
            // 下一个数字只能与当前结尾数字保持一致，只有一种可能
            b = c;
        }
        return a+b;
    }
};
```
