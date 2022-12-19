```Java
class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> ans = new ArrayList<Integer>();
        boolean[] vis = new boolean[1 << n];
        ans.add(start);
        vis[start] = true;

        for (int i = 1; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                // 1 << j实现从低位向高位依次翻转，默认为0开始
                // start ^ 转化为当前满足的数（相当于给了offset）
                int t = start ^ (1 << j);
                // 若未在结果中出现则写入
                if (!vis[t]) {
                    start = t;
                    break;
                }
            }
            vis[start] = true;
            ans.add(start);
        }

        return ans;
    }
}
```
![image.png](https://pic.leetcode-cn.com/9938197c27c85ed801e3cf9f5c74ac0e32d3ca25371ca5274b505e062197d961-image.png)
