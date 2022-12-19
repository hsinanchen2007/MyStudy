### 解题思路
方法1 递归思路
    
```
int fib(int N) {
        if (N == 0) {
            return 0;
        } else if (N == 1 || N == 2) {
            return 1;
        } else {
            return fib(N - 1) + fib(N - 2);
        }
    }
```
方法2 递归+记录已计算结果

### 代码

```java

HashMap<Integer, Integer> recordMap = new HashMap<Integer, Integer>();

    int fib(int N) {
        int tValue = 0;
        if(N == 0) {
            tValue = 0;
        }
        else if (N == 1 || N == 2) {
            tValue = 1;
        } else if (recordMap.get(N) != null) {
            tValue = recordMap.get(N);
        } else {
            tValue = fib(N - 1) + fib(N - 2);
            recordMap.put(N, tValue);
        }
        return tValue;
    }

```
方法3 自底向上的解法
```
int fib(int N) {
        if (N <= 1) {
            return N;
        }
        if (N == 2) {
            return 1;
        }
        int current = 0;
        int prev1 = 1;
        int prev2 = 1;

        for (int i = 3; i <= N; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
```
