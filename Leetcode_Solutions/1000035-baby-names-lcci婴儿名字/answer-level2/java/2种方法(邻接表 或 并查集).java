# PS:
无论使用哪种方法，代码都会变得又长又臭。

# 邻接表代码
```java
class Solution {
    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        int init_size = names.length;
        Map<String, Integer> ori_map = new HashMap<>(init_size);
        for (String str : names) {
            int idx = str.indexOf('(');
            ori_map.put(str.substring(0, idx), Integer.valueOf(str.substring(idx + 1, str.length() - 1)));
        }
        //syn_map看作是邻接表
        Map<String, LinkedList<String>> syn_map = new HashMap<>(init_size);
        Map<String, Integer> idx_map = new HashMap<>(init_size);
        int count = 0;
        for (String str : synonyms) {
            int idx = str.indexOf(',');
            String a = str.substring(1, idx), b = str.substring(idx + 1, str.length() - 1);
            if (!idx_map.containsKey(a))
                idx_map.put(a, count++);
            if (!idx_map.containsKey(b))
                idx_map.put(b, count++);
            LinkedList<String> list = syn_map.computeIfAbsent(a, unused -> new LinkedList<>());
            list.addLast(b);
            list = syn_map.computeIfAbsent(b, unused -> new LinkedList<>());
            list.addLast(a);
        }
        boolean[] selected = new boolean[count];
        LinkedList<String> res = new LinkedList<>();
        for (Map.Entry<String, LinkedList<String>> entry : syn_map.entrySet()) {
            String name = entry.getKey();
            if (selected[idx_map.get(name)])
                continue;
            selected[idx_map.get(name)] = true;
            LinkedList<String> list = entry.getValue();
            PriorityQueue<String> priorityQueue = new PriorityQueue<>();
            priorityQueue.add(name);
            while (!list.isEmpty()) {
                String temp_str = list.removeFirst();
                if (!selected[idx_map.get(temp_str)]) {
                    priorityQueue.add(temp_str);
                    selected[idx_map.get(temp_str)] = true;
                    if (syn_map.containsKey(temp_str))
                        list.addAll(syn_map.get(temp_str));
                }
            }
            String base_name = priorityQueue.poll();
            int base_val = ori_map.remove(base_name);
            for (String str : priorityQueue) {
                Integer val = ori_map.remove(str);
                base_val += val == null ? 0 : val;
            }
            res.addLast(base_name + "(" + base_val + ")");
        }
        ori_map.forEach((k, v) -> res.addLast(k + "(" + v + ")"));
        return res.stream().toArray(String[]::new);
    }
}
```

# 并查集代码
```java
class Solution {
    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        Map<String, Integer> ori_map = new HashMap<>();
        for (String str : names) {
            int idx = str.indexOf('(');
            ori_map.put(str.substring(0, idx), Integer.valueOf(str.substring(idx + 1, str.length() - 1)));
        }
        Map<Integer, String> idxToStr_map = new HashMap<>();
        Map<String, Integer> strToIdx_map = new HashMap<>();
        int count = 0, len = synonyms.length, memo_idx = 0;
        int[][] memo = new int[len][2];
        for (String str : synonyms) {
            int idx = str.indexOf(',');
            String a = str.substring(1, idx), b = str.substring(idx + 1, str.length() - 1);
            if (!strToIdx_map.containsKey(a)) {
                strToIdx_map.put(a, count);
                idxToStr_map.put(count++, a);
            }
            if (!strToIdx_map.containsKey(b)) {
                strToIdx_map.put(b, count);
                idxToStr_map.put(count++, b);
            }
            memo[memo_idx][0] = strToIdx_map.get(a);
            memo[memo_idx++][1] = strToIdx_map.get(b);
        }
        DSU dsu = new DSU(count);
        for (int[] pair : memo)
            dsu.union(pair[0], pair[1]);

        Map<Integer, LinkedList<Integer>> target_map = new HashMap<>();
        for (int i = 0; i < count; ++i) {
            int key = dsu.find(i);
            LinkedList<Integer> list = target_map.computeIfAbsent(key, unused -> new LinkedList<>());
            list.addLast(i);
        }
        LinkedList<String> res = new LinkedList<>();
        for (LinkedList<Integer> list : target_map.values()) {
            PriorityQueue<String> priorityQueue = new PriorityQueue<>(list.size());
            for (int idx : list)
                priorityQueue.offer(idxToStr_map.get(idx));
            String base_name = priorityQueue.poll();
            int base_val = ori_map.remove(base_name);
            for (String str : priorityQueue) {
                Integer val = ori_map.remove(str);
                base_val += val == null ? 0 : val;
            }
            res.addLast(base_name + "(" + base_val + ")");
        }
        ori_map.forEach((k, v) -> res.addLast(k + "(" + v + ")"));
        return res.stream().toArray(String[]::new);
    }
}

class DSU {
    int[] parent;

    public DSU(int len) {
        parent = new int[len];
        for (int i = 0; i < len; ++i)
            parent[i] = i;
    }

    public int find(int x) {
        return parent[x] != x ? parent[x] = find(parent[x]) : x;
    }

    public void union(int x, int y) {
        parent[find(x)] = find(y);
    }
}
```
