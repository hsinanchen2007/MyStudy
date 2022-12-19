### 解题思路
走一个房间就标记一个房间,统计最后走过的房间数是否和所有房间数相等
![QQ截图20200124142449.png](https://pic.leetcode-cn.com/5ca6a0205f71f9847baaf735719a629c06a97c92c44c8da8b87da6a4e9e92de7-QQ%E6%88%AA%E5%9B%BE20200124142449.png)

### 代码

```java
class Solution {
    private int []vis;
    private boolean f = false;
    private int sum = 0;
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        if (rooms == null || rooms.size() == 0) {
            return true;
        }
        vis = new int [rooms.size()];
        dfs(rooms, 0);
        return f;
    }

    private void dfs(List<List<Integer>> rooms, int cur) {
        vis[cur] = 1;
        ++sum;
        if (sum == rooms.size()) {
            f = true;
        }
        if(!f) {
            for (int i = 0; i < rooms.get(cur).size(); i++) {
                if (vis[rooms.get(cur).get(i)] == 0) {
                    dfs(rooms, rooms.get(cur).get(i));
                }
            }
        }
    }
}
```