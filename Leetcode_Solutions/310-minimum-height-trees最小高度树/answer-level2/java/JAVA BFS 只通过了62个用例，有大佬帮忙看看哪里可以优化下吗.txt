{
        // 初始化图
        HashMap<Integer, HashSet<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.put(i, new HashSet<>());
        }

        for (int[] p : edges) {
            graph.get(p[0]).add(p[1]);
            graph.get(p[1]).add(p[0]);
        }
        List<Integer> integers = new ArrayList<>();
        HashMap<Integer, Integer> gaodu = new HashMap<>();//记录每个跟节点对应的高度
        int minHeight = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            boolean[] visited = new boolean[n];
            // 分别遍历 这N个节点作为跟节点
            Queue<Integer> queue = new LinkedList<>();
            queue.add(i);
            int heigh = 0;
            while (!queue.isEmpty()) {
                int size = queue.size();
                while (size > 0) {
                    Integer cur = queue.poll();
                    // 当前节点已经访问过了，没有必要再次访问了
                    if (visited[cur]) {
                        continue;
                    }
                    visited[cur] = true;
                    for (Integer p : graph.get(cur)) {
                        // 这个当前要删除的节点对应的 其他节点
                        if (visited[p]) {
                            continue;
                        }
                        queue.add(p);
                    }
                    size--;
                }
                // 当size 删减到0，说明当层已经遍历完成了。
                heigh = heigh + 1;// 高度+1了
                if (heigh > minHeight) {
                    // 已经发现不满足了，提前结束
                    break;
                }
            }
            // 以i为跟节点的树已经构造完毕了
            gaodu.put(i, heigh);
            if (heigh <= minHeight) {
                minHeight = heigh;
            }
        }

        for (Map.Entry<Integer, Integer> entity : gaodu.entrySet()) {
            if (entity.getValue() == minHeight) {
                integers.add(entity.getKey());
            }
        }
        return integers;
    }