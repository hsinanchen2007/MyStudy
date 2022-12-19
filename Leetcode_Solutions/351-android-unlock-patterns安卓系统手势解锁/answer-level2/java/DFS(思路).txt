**思路:** 枚举所有起点, 传入所有可能的步数, 搜索可能性
**关键:** 合法路径的判断
### 合法路径判断
其实就是找规律
1. 上下左右移动、马的移动(例如1->8, 1->6): 起点+终点=奇数, 永远合法
2. 斜方向移动(例如5->1, 5->3): 不在同一行与同一列, 前提是要排除掉对角线移动, 永远合法
3. 对角线移动(例如1->9, 3->7): 起点+终点=8, 必须在条件2之前判断, 排除掉特殊情况, 此处判断中间位置是否访问即可
4. 边长移动(例如1->3, 1->7): 除了条件1、2、3之外剩下的就是边长移动情况, 此处判断中间位置是否访问即可
# 代码
```
class Solution {
    private int cnt;
    public int numberOfPatterns(int m, int n) {
        for (int i = 0; i < 9; ++i) {
            for (int j = m; j <= n; ++j) {
                helper(i, -1, new boolean[9], j);
            }
        }
        return cnt;
    }
    private void helper(int index, int pre, boolean[] visited, int steps) {
        if (--steps == 0) {
            ++cnt;
        } else {
            visited[index] = true;
            for (int i = 0; i < 9; ++i) {
                if (legal(i, index, visited)) helper(i, index, visited, steps);
            }
            visited[index] = false;
        }
    }
    private boolean legal(int index, int pre, boolean[] visited) {
        if (visited[index]) return false;
        if ((index + pre != 8) && ((index + pre) % 2 == 1 || (index % 3 != pre % 3 && index / 3 != pre / 3))) return true;
        return visited[(index + pre) / 2];
    }
}
```