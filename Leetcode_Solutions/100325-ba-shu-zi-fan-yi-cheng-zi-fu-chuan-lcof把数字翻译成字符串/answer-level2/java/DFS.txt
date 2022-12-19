![QQ截图20200403094042.png](https://pic.leetcode-cn.com/bcc17af20e389b63ca6f17cf26994d8321db3bd568da251007846256a747fe3b-QQ%E6%88%AA%E5%9B%BE20200403094042.png)


### 解题思路
简单易理解dfs
对每一位数字：若它和它下一位的数字之和小于26，则算一种情况

### 代码

```java
class Solution {
    int res = 0;

    
    void dfs(String str, int n) {
        if (n >= str.length() - 1) {
            res++;
            return;
        }
        dfs(str, n + 1);
        if (str.charAt(n) - '0' > 0 && n + 1 < str.length() && (str.charAt(n) - '0') * 10 + str.charAt(n + 1) - '0' < 26) {
            dfs(str, n + 2);
        }
    }
    public int translateNum(int num) {
        res = 0;
        String str = String.valueOf(num);
        dfs(str, 0);
        return res;
    }
}
```