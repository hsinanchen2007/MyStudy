# 双层拓扑排序
- 预处理：若group ID为-1，则为其赋予一个新的group ID
- 基于项目的组间依赖关系，对group ID进行拓扑排序，若排序不成功，直接退出
- 基于项目的组内依赖关系，对上一步结果中的每一个group内的项目进行拓扑排序，若排序不成功，直接退出
- 由于group和每个group内的项目都是可进行排序的实体，故定义一个基类Sortable，即可使用一套拓扑排序代码进行两类实体的排序

```
class Solution {
    /* 基类，用于拓扑排序 */
    private static class Sortable {
        public int ID;
        public Set<Sortable> next;

        public Sortable(int ID) {
            this.ID = ID;
            this.next = new HashSet<>(); // 后继节点
        }
    }

    /* 项目类 */
    private static class Item extends Sortable {

        public Item(int ID) {
            super(ID);
        }
    }

    /* 项目组类 */
    private static class Group extends Sortable {
        public Map<Integer, Item> items = new HashMap<>();              // 项目组负责的项目
        public Map<Integer, Integer> itemInDegrees = new HashMap<>();   // 各项目节点的入度

        public Group(int ID) {
            super(ID);
        }
    }

    /* 拓扑排序结果类 */
    private static class SortResult {
        public boolean success;
        public List<Sortable> result;

        public SortResult(boolean success, List<Sortable> result) {
            this.success = success;
            this.result = result;
        }
    }

    private Map<Integer, Group> groups = new HashMap<>();           // 以项目组为节点构成的图
    private Map<Integer, Integer> groupInDegrees = new HashMap<>(); // 项目组节点的入度，方便拓扑排序

    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        initialize(n, m, group, beforeItems);
        SortResult sortedGroups = topologicalSort(groups, groupInDegrees);  // 首先进行项目组的拓扑排序
        if (!sortedGroups.success) return new int[0];
        int[] ans = new int[n];
        int curr = 0;
        for (Sortable s1 : sortedGroups.result) {                           // 再对每组中的项目进行拓扑排序
            Group g = (Group) s1;
            SortResult sortedItems = topologicalSort(g.items, g.itemInDegrees);
            if (!sortedItems.success) return new int[0];
            for (Sortable s2 : sortedItems.result) {
                Item item = (Item) s2;
                ans[curr++] = item.ID;
            }
        }
        return ans;
    }

    /**
     * 拓扑排序代码
     * @param graph     待排序的图
     * @param inDegrees 图中各节点的入度
     * @return          排序结果
     */
    private SortResult topologicalSort(Map<Integer, ? extends Sortable> graph, Map<Integer, Integer> inDegrees) {
        List<Sortable> list = new ArrayList<>();
        Queue<Sortable> queue = new LinkedList<>();
        for (Map.Entry<Integer, Integer> entry : inDegrees.entrySet())  {
            if (entry.getValue() == 0)
                queue.offer(graph.get(entry.getKey()));
        }
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Sortable sortable = queue.poll();
                for (Sortable s : sortable.next) {
                    int inDegree = inDegrees.get(s.ID);
                    if (inDegree == 1) queue.offer(s);
                    inDegrees.put(s.ID, inDegree - 1);
                }
                list.add(sortable);
            }
        }
        boolean success = list.size() == graph.size();
        return new SortResult(success, list);
    }

    /* 成员变量的预处理 */
    private void initialize(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        int t = 0;
        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            items[i] = new Item(i);
            if (group[i] == -1)
                group[i] = (m + t++);

        }
        for (int i = 0; i < m + t; i++) {
            groups.put(i, new Group(i));
            groupInDegrees.put(i, 0);
        }
        for (int i = 0; i < n; i++) {
            Group currentGroup = groups.get(group[i]);
            currentGroup.items.put(i, items[i]);
            currentGroup.itemInDegrees.put(i, 0);
        }
        for (int i = 0; i < n; i++) {
            Group currentGroup = groups.get(group[i]);
            for (int j : beforeItems.get(i)) {
                if (group[i] == group[j]) {
                    items[j].next.add(items[i]);
                    currentGroup.itemInDegrees.compute(i, (k, v) -> v + 1);
                } else {
                    groups.get(group[j]).next.add(currentGroup);
                }
            }
        }
        for (Map.Entry<Integer, Group> entry : groups.entrySet()) {
            Group g = entry.getValue();
            for (Sortable next : g.next) {
                groupInDegrees.compute(next.ID, (k, v) -> v + 1);
            }
        }
    }
}
```
