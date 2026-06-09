![截屏2020-02-24下午12.04.35.png](https://pic.leetcode-cn.com/30cf47bef31f89545a159d0e4608d43d602c7ef1b98f9ecfda2e9213745e159a-%E6%88%AA%E5%B1%8F2020-02-24%E4%B8%8B%E5%8D%8812.04.35.png)


两个记忆化搜索（才知道怎么写记忆化的，把dfs中的参数和值放在一起，如果出现过之前的参数就返回保存的值）

```
class Solution {
    
    char[] c = new char[]{'a','e','i','o','u'};
    int n = 0;
    Map <String, Integer> map = new HashMap<>();
    int mod = 1_000_000_007;
    
    public int dfs(char pre, int cur) {
        if (cur == n) return 1;
        if (map.containsKey(pre + " " + cur)) {
            return map.get(pre + " " + cur);
        }
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            if (pre == 'a' && c[i] == 'e') {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            } else if (pre == 'e' && (c[i] == 'a' || c[i] == 'i')) {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            } else if (pre == 'i' && c[i] != 'i') {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            } else if (pre == 'o' && (c[i] == 'i' || c[i] == 'u')) {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            } else if (pre == 'u' && c[i] == 'a') {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            }
            map.put(pre + " " + cur, ans);
        }
        return ans;
    }
    
    public int countVowelPermutation(int n) {
        if (n == 1) return 5;
        int ans = 0;
        this.n = n;
        for (int i = 0; i < 5; i++) {
            ans += dfs(c[i], 1);
            ans = ans % mod;
        }
        return ans;
    }
}
```
```
class Solution {
    
    char[] c = new char[]{'a','e','i','o','u'};
    int n = 0;
    // Map <String, Integer> map = new HashMap<>();
    int[][] memo;
    int mod = 1_000_000_007;
    
    public int dfs(char pre, int cur) {
        if (cur == n) return 1;
        if (memo[pre - 'a'][cur] != -1) {
            return memo[pre - 'a'][cur];
        }
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            if (pre == 'a' && c[i] == 'e') {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            } else if (pre == 'e' && (c[i] == 'a' || c[i] == 'i')) {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            } else if (pre == 'i' && c[i] != 'i') {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            } else if (pre == 'o' && (c[i] == 'i' || c[i] == 'u')) {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            } else if (pre == 'u' && c[i] == 'a') {
                ans += dfs(c[i], cur + 1);
                ans = ans % mod;
            }
            memo[pre - 'a'][cur] = ans;
        }
        return ans;
    }
    
    public int countVowelPermutation(int n) {
        if (n == 1) return 5;
        int ans = 0;
        this.n = n;
        memo = new int[26][n + 1];
        for (int[] i : memo) Arrays.fill(i, -1);
        for (int i = 0; i < 5; i++) {
            ans += dfs(c[i], 1);
            ans = ans % mod;
        }
        return ans;
    }
}
```

DP解法应该很容易看懂吧（ % mod 有点多，影响观看，但是又不知道什么时候取余，索性全都取余）。

```
class Solution {
    
    int mod = 1_000_000_007;
    
    public int countVowelPermutation(int n) {
        if (n == 1) return 5;
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int z = 1; z < n; z++) {
            int pa = a;
            int pe = e;
            int pi = i;
            int po = o;
            int pu = u;
            a = ((pe + pu) % mod + pi) % mod;
            e = (pa + pi) % mod;
            i = (pe + po) % mod;
            o = pi;
            u = (pi + po) % mod;
        }
        return ((((a + e) % mod + i) % mod + o) % mod + u) % mod;
    }
}
```


