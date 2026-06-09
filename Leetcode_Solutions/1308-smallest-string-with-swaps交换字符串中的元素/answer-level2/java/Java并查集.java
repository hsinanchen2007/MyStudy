### 解题思路


### 代码

```java
class Solution {
    // 并查集
    class DisjointSetUnion{
        public int[] pre;

        public DisjointSetUnion(int num){
            this.pre = new int[num];
            for (int i = 0; i < num; i++) {
                this.pre[i] = i;
            }
        }

        public DisjointSetUnion(int[] nums){
            this.pre = new int[nums.length];
            for (int i = 0; i < nums.length; i++) {
                this.pre[nums[i]] = nums[i];
            }
        }

        public int find(int x){
            int root = x;
            while (root != this.pre[root]){
                root = this.pre[root];
            }
            // 路径压缩
            while (x != root){
                int tmp = x;
                x = this.pre[x];
                this.pre[tmp] = root;
            }
            return root;
        }

        public void union(int x, int y){
            this.pre[find(x)] = find(y);
        }
    }

    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        // 1. 暴力, 遍历Pairs只要交换后小于当前字符串就交换, 直到不能交换
        
        // 2. 并查集, 将可交换的字符聚集到一起, 构成最小的字典序, 将各个聚簇的最小结果合并
        DisjointSetUnion dsu = new DisjointSetUnion(s.length());

        for (List<Integer> pair : pairs) {
            int x = pair.get(0), y = pair.get(1);
            dsu.union(x, y);
        }
        // 将元素聚集成各个聚簇
        HashMap<Integer, List<Character>> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.computeIfAbsent(dsu.find(i), k -> new ArrayList<Character>()).add(s.charAt(i));
        }
        // 对每个聚簇排序
        for (Integer integer : map.keySet()) {
            Collections.sort(map.get(integer));
        }

        // 合并聚簇
        StringBuilder sb = new StringBuilder();
        // 记录每个聚簇元素索引指针
        HashMap<Integer, Integer> curPos = new HashMap<>();
        for (Integer integer : map.keySet()) {
            curPos.put(integer, 0);
        }
        for (int i = 0; i < s.length(); i++) {
            int key = dsu.find(i);
            sb.append(map.get(key).get(curPos.get(key)));
            curPos.put(key, curPos.get(key) + 1);
        }
        return sb.toString();
    }
}
```