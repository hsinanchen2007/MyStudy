https://www.programcreek.com/2014/05/leetcode-pain-fence-java/

https://segmentfault.com/a/1190000005740990

如果第1根柱子与第2根柱子颜色一样，那么两根柱子总共只有k种着色方案。第3根柱子的颜色有k-1种。

如果第1根柱子与第2根柱子颜色不一样，那么两根柱子总共的着色方案是 k * (k - 1)。第3根柱子的颜色有k种。

所以三根柱子的总颜色是：k * (k-1) + k * (k-1) * k = (k-1) * (k + k * k)

```c++ []
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }
        
        int first = k;
        int second = k * k;
        
        if (n == 1) {
            return first;
        } else if (n == 2) {
            return second;
        } else {
            int third = 0;
            for (int i = 3; i <= n; i++) {
                third = (k - 1) * (first + second);
                first = second;
                second = third;
            }
            return third;
        }
    }
};
```
