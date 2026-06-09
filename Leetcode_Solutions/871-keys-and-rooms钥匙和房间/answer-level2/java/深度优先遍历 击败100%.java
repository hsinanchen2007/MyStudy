### 解题思路
思路见代码

### 代码

```java
import java.util.List;

/**
 * 解题思路：
 * 1. 设置一个变量表示该房间有没有被访问过
 * 2. 进行深度优先遍历
 */
class Solution {
    // 设置几个工具参数
    private boolean[] visited;
    private List<List<Integer>> rooms;
    private int count;  // 记录已经进入了哪些房间

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        visited = new boolean[rooms.size()];
        this.rooms = rooms;
        count = 0;

        // 深度优先遍历
        dfs(0);

        return count == rooms.size();
    }

    // 进行深度优先遍历 对i号房间进行深度优先遍历
    private void dfs(int i){
        if(!visited[i]){
            visited[i] = true;
            count ++;
        }else {
            return;
        }
        List<Integer> keys = rooms.get(i);
        // 对keys中的每个钥匙进行遍历
        for(int j=0; j<keys.size(); j++){
            dfs(keys.get(j));
        }
    }
}
```