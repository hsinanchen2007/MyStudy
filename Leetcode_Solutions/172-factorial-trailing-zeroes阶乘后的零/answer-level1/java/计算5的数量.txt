### 解题思路
10 = 2 * 5，在所有情况下2的数量都大于5，所以只需要计算因数5的数量。
```
3 = 1 * 2 * 3 没有5，所以答案是0；
5 = 1 * 2 * 3 * 4 * 5，答案为1
```
计算方法：
```
n = 100:
1. n / 5 = 20, 则1 * 5 <= 100,....,20 * 5 <= 100, 从而f(100) = f(20) + 20;
2. ...
```

![image.png](https://pic.leetcode-cn.com/25fc08e6f87f60c753940ab47f206cb6484192b08ab224e50147ec3d12c43673-image.png)

### 代码

```java
class Solution {
    public int trailingZeroes(int n) {
        int cnt = 0;
        while (n > 0) {
            n /= 5;
            cnt += n;
        }

        return cnt;
    }
}
```