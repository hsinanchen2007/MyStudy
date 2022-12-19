建议在看代码前，先看我之前写的一篇题解。
[1238. 循环码排列](https://leetcode-cn.com/problems/circular-permutation-in-binary-representation/solution/di-gui-yi-huo-jie-fa-jue-dui-jing-bao-by-pppp-9/)

上代码
``` Java
class Solution {
    List<Integer> res = new ArrayList<>();
    int v;
    public List<Integer> grayCode(int n) {
        v = 0;
        res.add(v);
        if (n == 0) return res;
        calGray(n - 1);
        return res;
    }
    void calGray(int n) {
        if (n == 0) {
            res.add(v ^= 1);
        } else {
            calGray(n - 1);
            res.add(v ^= (1 << n));
            calGray(n - 1);
        }
    }
}
```