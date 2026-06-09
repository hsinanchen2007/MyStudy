### 解题
中间数据缓存方式

### 代码

```java
class Solution {
    public int tribonacci(int n) {
        //创建数组变量存储中间计算值
        int[] temp = new int[n + 1];
        return dfs(temp, n);
    }

    private int dfs(int[] temp, int n) {
        //递归边界 [0,1,1]
        if(n <= 0) {
            return 0;
        }
        if(n == 1 || n == 2) {
            return 1;
        }

        if(temp[n] != 0) {
            return temp[n];
        }
        //递但不归 因为保存了计算的值向下传递（倒着算）
        int sum = dfs(temp ,n - 3) + dfs(temp, n - 2) + dfs(temp, n - 1);
        temp[n] = sum;
        return sum;
    }
}
```