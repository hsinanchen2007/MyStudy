d为2
![image.png](https://pic.leetcode-cn.com/2b5381e06e0391ff59c790a86fa7bcb3e15de0460eed2bdee8f2308654a9fc80-image.png)
d为3
![image.png](https://pic.leetcode-cn.com/0e86b6301c8c6bc7d9f3afa6691c0bd40e5801e978c0d62eccfd8a80f8537748-image.png)

```
class Solution {
    public String multiply(String a, String b) {
        int d = 2; // 两两一组运算
        int al = a.length();
        int bl = b.length();
        int[] as = new int[al / d + (al % d > 0 ? 1 : 0)];
        int[] bs = new int[bl / d + (bl % d > 0 ? 1 : 0)];
        int at = as.length;
        int bt = bs.length;
        int[] lx = new int[at + bt];
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i <= at - 1; i++) { // 用于将a中的string分组
            t1 = al - i * d;
            t2 = t1 - d;
            as[at - 1 - i] = Integer.valueOf(t2 < 0 ? a.substring(0, t1) : a.substring(t2, t1));
        }
        for (int i = 0; i <= bt - 1; i++) { // 用于将b中的string分组
            t1 = bl - i * d;
            t2 = t1 - d;
            bs[bt - 1 - i] = Integer.valueOf(t2 < 0 ? b.substring(0, t1) : b.substring(t2, t1));
        }
        for (int i = at - 1; i >= 0; i--) { // 计算各级，并保存到数组中，数组中每一个元素代表的级跟元素的下标有关
            for (int j = bt - 1; j >= 0; j--) {
                lx[at + bt - 2 - i - j] += as[i] * bs[j];
            }
        }
        String res = "";
        int acc = 0;
        for (int i = 0; i < lx.length; i++) { // 将结果（分权）相加，超过t的进位
            lx[i] = lx[i] + acc;
            int t = (int) Math.pow(10, d);
            acc = lx[i] / t;
            t1 = lx[i] % t;
            res = (t1 < 10 ? "0" + t1 : t1) + res; //如果d为3，这里应该是00！！
            // d为3 res = (t1 < 100 ? (t1 < 10? "00" + t1 : "0" + t1) : t1) + res;
        }
        int i = 0;
        t2 = res.length();
        for (; i < t2; i++) { // 去掉开头的0
            if (res.charAt(i) != '0') {
                break;
            }
        }
        if (i > 0) {
            res = res.substring(i);
            if (i == t2) return "0";
        }

        return res;
    }
}
```
