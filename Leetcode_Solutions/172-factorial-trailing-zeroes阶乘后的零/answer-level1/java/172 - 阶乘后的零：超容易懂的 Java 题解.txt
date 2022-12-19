> 有关更多题解，请访问 Gitee 中的项目【[myleetcode](https://gitee.com/guobinhit/myleetcode)】，欢迎大家共同参与此项目！

>

```
public class _172 {
    public int trailingZeroes(int n) {
        int ans = 0;
        while (n > 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
}
```
