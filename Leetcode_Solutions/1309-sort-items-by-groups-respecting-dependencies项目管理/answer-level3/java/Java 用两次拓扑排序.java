### 解题思路

1. 分别对group和item进行拓扑排序，得到group拓扑排序后的list和item拓扑排序后的list

2. 然后简历一个group -> item 的map

3. 遍历itemlist，将item和其对应的group加入到map中

4. 最后根据grouplist的顺序遍历map，得到结果 

### 代码

```java
class Solution {
    Map<Integer, List<Integer>> groupGraph;
    Map<Integer, List<Integer>> itemGraph;
    int[] groupIndegree;
    int[] itemIndegree;
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        groupGraph = new HashMap();
        itemGraph = new HashMap();
        for (int i = 0; i < n; i ++) {
            if (group[i] == -1) group[i] = m++;
        }
        for (int i=0;i<m;i++) {
            groupGraph.put(i, new ArrayList());      
        }
    
        for (int i=0;i<n;i++) {
            itemGraph.put(i, new ArrayList());      
        }
        groupIndegree = new int[m];
        itemIndegree = new int[n];
        computeGroupGraph(group, beforeItems);
        computeItemGraph(group, beforeItems);
        List<Integer> grouplist = topologicalSort(groupGraph, groupIndegree, m);
        List<Integer> itemlist = topologicalSort(itemGraph, itemIndegree, n);
        Map<Integer, List<Integer>> groupToItems = new HashMap<>();
        for (int item : itemlist) {
            groupToItems.computeIfAbsent(group[item], k -> new ArrayList()).add(item);
        }
        if (grouplist.size() == 0 || itemlist.size() == 0) return new int[0];
        int[] res =  new int[n];
        int idx = 0;
        for (int g : grouplist) {
            List<Integer> l = groupToItems.getOrDefault(g, new ArrayList());
            for (int item : l) {
                res[idx++] = item;
            }
        }
        return res;
    }

    public List<Integer>topologicalSort(Map<Integer, List<Integer>> graph, int[] indegree, int n ) {
        Queue<Integer> q = new LinkedList<>();
        List <Integer> list = new ArrayList<Integer>();

        for (int k : graph.keySet()) {
            if (indegree[k] == 0) {
                q.add(k);
            }
        }
        while (!q.isEmpty()) {
            int top = q.poll();
            n --;
            list.add(top);
            for (int neighbor : graph.get(top)) {
                if (--indegree[neighbor] == 0) {
                    q.add(neighbor);
                }
            }
            

        }
        return n == 0 ? list : new ArrayList<Integer>();
    }

    public void computeGroupGraph(int[] group, List<List<Integer>> beforeItems) {
        for (int i = 0; i < group.length; i ++) {
            int toGroup = group[i];
            for (int fromGraph : beforeItems.get(i)) {
                if (group[fromGraph] != toGroup) {
                    groupGraph.computeIfAbsent(group[fromGraph], k -> new ArrayList()).add(toGroup);
                    groupIndegree[toGroup] ++;
                }
            }
        }
    }

    public void computeItemGraph(int[] group, List<List<Integer>> beforeItems) {
        for (int i = 0; i < group.length; i ++) {
            int toItem =i;
            for (int fromItem : beforeItems.get(toItem)) {
                if (fromItem != toItem) {
                    itemGraph.computeIfAbsent(fromItem, k -> new ArrayList()).add(toItem);
                    itemIndegree[toItem] ++;
                }
            }
        }
    }

}
```