> 有关更多题解，请访问 Gitee 中的项目【[myleetcode](https://gitee.com/guobinhit/myleetcode)】，欢迎大家共同参与此项目！

>

```
public class _202 {
    public boolean isHappy(int n) {
        Set<Integer> inLoop = new HashSet<Integer>();
        int squareSum, remain;
        while (inLoop.add(n)) {
            squareSum = 0;
            while (n > 0) {
                remain = n % 10;
                squareSum += remain * remain;
                n /= 10;
            }
            if (squareSum == 1) {
                return true;
            } else {
                n = squareSum;
            }
        }
        return false;
    }
}
```
