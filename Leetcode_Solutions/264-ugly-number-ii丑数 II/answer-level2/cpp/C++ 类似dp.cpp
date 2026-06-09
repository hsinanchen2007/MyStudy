### 解题思路
1、暴力
2、利用最小堆，先扔1进堆里。然后每次拿堆顶最小的再乘一下2、3、5，然后扔堆里。直到拿堆顶次数为n。
3、dp，思路是n的丑数一定是由以前的丑数乘2、3、5得到的。那么可以对2、3、5都维持一个index，当对应的index乘对应的数是最小的时候，那么这个数就是当前的最小丑数，此时我们已经遍历的丑数个数+1，并且让对应的index+1。这样一直遍历到第n个丑数。

### 代码

```cpp
class Solution {
public:
    int min3(int a, int b, int c) {
        if (a>b) {
            return b > c ? c : b;
        } else {
            return a > c ? c : a;
        }
    }
    
    int nthUglyNumber(int n) {
        vector<int> v = vector<int>(n, 0);
        v[0] = 1;
        int index2 = 0,  index3 = 0, index5 = 0;
        int k = 1;
        while (k < n) {
            int n2 = v[index2]*2;
            int n3 = v[index3]*3;
            int n5 = v[index5]*5;
            v[k] = min3(n2, n3, n5);
            if (v[k] == n2) index2++;
            if (v[k] == n3) index3++;
            if (v[k] == n5) index5++;
            k++;
        }
        return v[n-1];
    }
};
```