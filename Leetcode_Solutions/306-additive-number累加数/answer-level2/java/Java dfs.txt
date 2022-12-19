此题和 [842. 将数组拆分成斐波那契序列](https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/)，类似，但这里没有限制每个数字在 Integer.MAX_VALUE 以内，因此我们就不能用 List<Integer> 保存当前已有的数字了，而是用 List<String> 保存。
关于两个 String 相加是否正确，我们要手动实现。

```java
class Solution {
    public boolean isAdditiveNumber(String num) {
        List<String> res = new ArrayList();
        return dfs(num, 0, res);
    }

    public boolean dfs(String S, int index, List<String> res) {
        if (index == S.length()) return res.size() > 2;
        for (int i = index + 1; i <= S.length(); i ++) {
            String f3 = S.substring(index, i);
            if (f3.length() > 1 && S.charAt(index) == '0') break;
            String f2 = res.size() >= 1? res.get(res.size() - 1) : "";
            String f1 = res.size() >= 2? res.get(res.size() - 2) : "";
            res.add(f3);
            if ((f1 == "" || f2 == "" || check(f1, f2, f3)) && dfs(S, i, res)) return true;
            res.remove(res.size() - 1);
        }
        return false;
    }

    boolean check(String f11, String f22, String f33) {
        int n1 = f11.length(), n2 = f22.length(), n3 = f33.length();
        int i = 0, r = 0;
        int t = Math.max(n1, n2);
        if (t != n3 && (t + 1) != n3) return false;
        String f1 = new StringBuffer(f11).reverse().toString();
        String f2 = new StringBuffer(f22).reverse().toString();
        String f3 = new StringBuffer(f33).reverse().toString();
        // 反转字符串，因为这里只用一个指针 i 从0开始加。不反转的话要用2个指针从 n1 - 1, n2 - 1 开始

        while (i < n1 || i < n2 || r > 0) {
            int c1 = (i < n1)? f1.charAt(i) - '0' : 0;
            int c2 = (i < n2)? f2.charAt(i) - '0' : 0;
            int c3 = f3.charAt(i) - '0';
            if ((c1 + c2 + r) % 10 != c3) return false;
            else r = (c1 + c2 + r) / 10;
            i ++;
        }   
        return true;
    }
}
```