### 解题思路
这个方法并没有动态规划好，不过也是个思路吧
执行时间4ms，还算中规中矩
递归的思路就是参数是剩余向右和向下的步数
剪枝的思路就是递归参数(a,b)和(b,a)的结果是一致的，所以只要记录下(a,b)那么(b,a)就可以被剪掉了

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(mark, 0, sizeof(mark));
        --m;
        --n;
        return recursive(m, n);
    }

    int recursive(int leftRight, int leftDown)
    {
        int small = min(leftRight, leftDown);
        int big = max(leftRight, leftDown);
        if (mark[small][big] > 0) return mark[small][big];
        if (leftRight == 0 || leftDown == 0) return 1;
        int res = 0;
        res += recursive(leftRight - 1, leftDown);
        res += recursive(leftRight, leftDown - 1);
        mark[small][big] = res;
        return res;
    }

    int mark[101][101];
};
```