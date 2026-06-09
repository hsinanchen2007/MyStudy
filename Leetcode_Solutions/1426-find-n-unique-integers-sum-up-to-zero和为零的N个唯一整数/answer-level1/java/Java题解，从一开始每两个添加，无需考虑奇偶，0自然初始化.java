每两个两个加入数组就是了，+1，-1，+2，-2，奇偶可以不判断，奇数必定有一个 0，最后落单剩下的一个自然就是 0 了，数组初始化就是 0 了。
```
class Solution {
    public int[] sumZero(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n / 2; i++) {
            res[i * 2] = i + 1;
            res[i * 2 + 1] = -(i + 1);
        }
        return res;
    }
}
```
