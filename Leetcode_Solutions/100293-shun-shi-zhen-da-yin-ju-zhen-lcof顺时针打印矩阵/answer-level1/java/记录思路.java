拿到题的第一想法是就控制好（x，y）然后蛇形输出结果就好，然后发现题目返回的是数组，所以就把输出的数存到数组中。
明确了输出顺序之后，需要知道的就是什么时候掉头。观察不同矩形的输出顺序可以发现，其实就是一圈一圈的输出数组中的元素。
明确是一圈圈输出之后，就可以利用边界限定来确定什么时候掉头。于是设置四个变量作为边界，每当触碰到边界就停止，直到有对立面的边界触碰到为止。
```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if (matrix.length == 0) return new int[0];
        int[] result = new int[matrix[0].length * matrix.length];
        int l, r, t, b, cnt;
        l = t = cnt = 0;
        r = matrix[0].length - 1;
        b = matrix.length - 1;
        while (true) {
            for (int i = l; i <= r; i++) result[cnt++] = matrix[t][i];
            if (++t > b) break;
            for (int i = t; i <= b; i++) result[cnt++] = matrix[i][r];
            if (--r < l) break;
            for (int i = r; i >= l; i--) result[cnt++] = matrix[b][i];
            if (--b < t) break;
            for (int i = b; i >= t; i--) result[cnt++] = matrix[i][l];
            if (++l > r) break;
        }
        return result;
    }
}
```
