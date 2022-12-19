DFS有点坑
```
class Solution {
    public boolean isBipartite(int[][] graph) {
        boolean[] visit = new boolean[graph.length];
        Map<Integer, Boolean> map = new HashMap<>(); // 结点和所属集合ID
        boolean ret = true; // "[[]]"返回true
        for (int i = 0; i < graph.length; i++) {
            if (!visit[i] && graph[i].length != 0) {
                ret = dfs(i, visit, graph, map);
                if (ret) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        //System.out.println(map);
        return ret;
    }

    public boolean dfs(int index, boolean[] visit, int[][] graph, Map<Integer, Boolean> map) {
        visit[index] = true;
        if (!map.containsKey(index)) {
            map.put(index, true);
            for (int i = 0; i < graph[index].length; i++) { // 防止前面遍历完一次分组，再来新的遍历，得先确定这个节点应该在哪个分组，不然后续遍历会出问题
                if (visit[graph[index][i]]) {
                    map.put(index, !map.get(graph[index][i]));
                    break;
                }
            }
        }
        boolean id = map.get(index);
        for (int i = 0; i < graph[index].length; i++) {
            if (visit[graph[index][i]]) {
                if (map.get(graph[index][i]) == id) { // 冲突
                    return false;
                } else {
                    continue;
                }
            } else {
                map.put(graph[index][i], !id);
                return dfs(graph[index][i], visit, graph, map);
            }
        }

        return true;
    }
}
```
DFS优化1：注意什么时候dfs为true，不可以直接返回，否则导致，后续节点不能遍历（还可以优化）
```
class Solution {
    public boolean isBipartite(int[][] graph) {
        boolean[] visit = new boolean[graph.length];
        Map<Integer, Boolean> map = new HashMap<>(); // 结点和所属集合ID
        boolean ret = true;
        for (int i = 0; i < graph.length; i++) {
            if (!visit[i] && graph[i].length != 0) {
                map.put(i, true);
                visit[i] = true;
                ret = dfs(i, visit, graph, map);
                if (ret) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return ret;
    }

    public boolean dfs(int index, boolean[] visit, int[][] graph, Map<Integer, Boolean> map) {
        boolean id = map.get(index);
        for (int i = 0; i < graph[index].length; i++) {
            if (!visit[graph[index][i]]) {
                visit[graph[index][i]] = true;
                map.put(graph[index][i], !id);
                if(!dfs(graph[index][i], visit, graph, map)) { // 为true，不可以直接返回
                    return false;
                }
            } else if (map.get(graph[index][i]) == id) {
                return false;
            }
        }

        return true;
    }
}
```


