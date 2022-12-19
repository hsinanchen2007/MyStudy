

```
class Solution {
public:
    int getw(int x) {
        int cnt = 0;
        while(x != 1) {
            if(x%2) x = 3*x+1;
            else x = x/2;
            ++cnt;
        }
        return cnt;
    }
    struct node {
        int val;
        int w;
    };
    int getKth(int lo, int hi, int k) {
        int n=hi-lo+1;
        node a[n];
        for(int i=0; i<n; ++i) {
            a[i].val = i+lo;
            a[i].w = getw(i+lo);
        }
        sort(a,a+n,[&](node a, node b) {
            return a.w == b.w?a.val<b.val:a.w<b.w;
        });
        return a[k-1].val;
    }
};
```
执行用时 :
28 ms
, 在所有 C++ 提交中击败了
92.64%
的用户
内存消耗 :
6.1 MB
, 在所有 C++ 提交中击败了
100.00%
的用户