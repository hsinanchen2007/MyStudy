# 思路
排好序之后就转化为最长上升子序列问题。只不过该上升子序列的“上升”条件是需要**2个属性**(**深度、高度**)来判定。
理解不了的话推荐先做简单点的[面试题 17.08. 马戏团人塔](https://leetcode-cn.com/problems/circus-tower-lcci/solution/xian-gen-ju-shen-gao-pai-xu-ruo-shen-gao-yi-yang-z/)

# 代码
```java [-排序+动态规划]
class Solution {
    public int pileBox(int[][] box) {
        int len = box.length;
        Arrays.sort(box, (a, b) -> a[0] == b[0] ? a[1] == b[1] ? b[2] - a[2] : b[1] - a[1] : a[0] - b[0]);
        int[] dp_val = new int[len];
        dp_val[0] = box[0][2];
        int res = dp_val[0];
        for (int i = 1; i < len; ++i) {
            int max_val = 0, base_depth = box[i][1], base_height = box[i][2];
            for (int j = 0; j < i; ++j)
                if (base_depth > box[j][1] && base_height > box[j][2])
                    max_val = Math.max(max_val, dp_val[j]);

            dp_val[i] = max_val + base_height;
            res = Math.max(res, dp_val[i]);
        }
        return res;
    }
}
```
