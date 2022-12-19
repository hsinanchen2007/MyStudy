### 解题思路
循环四条边就是让四条边的元素不断相加 这种比较简单
但是这种方式每次需要循环四条边  我们可以将4个循环放在一起
需要注意的是 第一条边新增的点比后面两条边多一次  最后一条边则比前两条少一次

### 代码
方案1:
```java
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int num = 1, count = (n + 1) / 2;
        for (int i = 0; i < count; i++) {
            for (int j = i; j < n - i; j++) ans[i][j] = num++;
            for (int j = i + 1; j < n - i; j++) ans[j][n - i - 1] = num++;
            for (int j = n - i - 2; j >= i; j--) ans[n- i - 1][j] = num++;
            for (int j = n - i - 2; j > i; j--) ans[j][i] = num++;
        }
        return ans;
    }
}
```
方案2:
```java
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int num = 1, count = (n + 1) / 2;
        for (int i = 0; i < count; i++) {
            // 每次都是上下两行遍历结束  所以i*2
            for (int j = i; j < n - i - 1; j++) {
                ans[i][j] = num;
                // 第一行新增n-i*2个 后面 两条边需要新增n-i*2-1个 
                ans[j + 1][n - i - 1] = (num + n - i * 2);
                ans[n - i - 1][n - 2 - j] = (num + (n - 1 - i * 2) * 2 + 1);
                if (j != n - i - 2)
                    ans[n - 2 - j][i] = (num + (n - 1 - i * 2) * 3 + 1);
                num++;
            }
            ans[i][n - i - 1] = num;
            // 遍历结束之后 相当于相加(n - 1 - i * 2) * 3
            num += (n - 1 - i * 2) * 3;
        }
        return ans;
    }
```