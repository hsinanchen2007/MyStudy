### 解题思路
dfs递归代码模版如下

```
visited = set();
void dfs(node, visited) {
    if(visited.contains(node)) return;
    visited.add(node);
    for(nodeChildren : node.children) {
        if(!visited.contains(nodeChildren)) {
            dfs(nodeChildren, visited);
        }
    }
}
```
可以将元数组定义为全部为0，然后将visited定义为1，
跳出递归判断为边界或是否为1
然后判断时候当前是否可达，可达则设置为1，
node.children 为四个方向的下一步，进行dfs
### 代码

```java
class Solution {
    int[] mMove = new int[]{-1, 1, 0, 0};
    int[] nMove = new int[]{0, 0, 1, -1};
    int k = 0;
    int res = 0;
    public int movingCount(int m, int n, int k) {
        int[][] tables = new int[m][n];
        this.k = k;
        dfs(tables, 0, 0);
        return res;
    }

    private void dfs(int[][] tables, int m, int n) {
        if (m < 0 || m >= tables.length || n < 0 || n >= tables[0].length || tables[m][n] == 1) {
            return;
        }
        int mSum = m == 100 ? 1 : (m % 10) + (m / 10);
        int nSum = n == 100 ? 1 : (n % 10) + (n / 10);
        if (mSum + nSum <= k) {
            tables[m][n] = 1;
            res++;
            for (int i = 0; i < 4; i++) {
                dfs(tables, m + mMove[i], n + nMove[i]);
            }
        }
    }
}
```