按照题目，第一反应是想到用递归。于是，就有了代码：

``` java
class Solution {
    public int sumNums(int n) {
        if (n == 1) return 1;
        return n + sumNums(n-1);
    }
}

```

但是递归的终止条件，用到了if，想想是否可以不用if呢？于是就有了下面的代码：

``` java
class Solution {
    public int sumNums(int n) {
        int ans = 0;
        boolean b = n > 0 && (ans = n + sumNums(n-1)) > 0;
        return ans;
    }
}
```

除了，用这种方法以外， 还有其它方法吗？本人还有一种思路：使用等差数列的求和公式，但是题目又要求不能使用乘除。

