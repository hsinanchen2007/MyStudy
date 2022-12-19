1. 通过List数组保存words之间的连通关系；
2. 分别从start和end进行广度优先搜索，并将遍历过程存放在Map中；
3. 如果出现“两头都可以到达某一个节点”的时候，表示start和end之间存在通路, 停止遍历并输出结果。  
```java
import java.util.*;

class Solution {
    public List<String> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<String> ans = new ArrayList<>();

        // 处理wordlist中不存在beginword的情况
        wordList.add(beginWord);
        // 去重，减少遍历
        Set<String> set = new HashSet<>(wordList);
        wordList = new ArrayList<>(set);

        // 使用List数组存储words之间的连通关系
        List<Integer>[] route = new ArrayList[wordList.size()];
        for (int i = 0; i < route.length; i++) {
            route[i] = new ArrayList();
            for (int j = 0; j < route.length; j++) {
                if (diffOne(wordList.get(i), wordList.get(j))) {
                    route[i].add(j);
                }
            }
        }

        // 查找起点和终点的索引
        int start = -1;
        int end = -1;
        for (int i = 0; i < wordList.size(); i++) {
            String str = wordList.get(i);
            if (str.equals(beginWord)) start = i;
            if (str.equals(endWord)) end = i;
        }
        // 不存在终点 直接返回null
        if (start == -1 || end == -1) return ans;

        // 双向广度优先遍历
        Queue<Rcd> queue_front = new LinkedList<>();
        Queue<Rcd> queue_back = new LinkedList<>();
        List<Integer> list_front = new ArrayList<>();
        list_front.add(start);
        List<Integer> list_back = new ArrayList<>();
        list_back.add(end);
        queue_front.add(new Rcd(start, list_front));
        queue_back.add(new Rcd(end, list_back));

        // 存储遍历过程
        Map<Integer, List<Integer>> map_front = new HashMap<>();
        Map<Integer, List<Integer>> map_back = new HashMap<>();
        Integer mid = -1;

        label:
        for (; !queue_back.isEmpty() || !queue_front.isEmpty(); ) {
            // 前向遍历
            int len = queue_front.size();
            for (int i = 0; i < len; i++) {
                Rcd rcd = queue_front.poll();
                // 只有最短路径 才保存并进行下一步的广度优先遍历
                if (!map_front.containsKey(rcd.now)) {
                    map_front.put(rcd.now, rcd.list);
                    for (Integer j : route[rcd.now]) {
                        if (!map_front.containsKey(j)) {
                            List<Integer> list = new ArrayList<>(rcd.list);
                            list.add(j);
                            queue_front.add(new Rcd(j, list));
                        }
                    }
                }
                // 两端都到达相同节点 退出遍历
                if (map_back.containsKey(rcd.now)) {
                    mid = rcd.now;
                    break label;
                }
            }
            // 后向遍历
            len = queue_back.size();
            for (int i = 0; i < len; i++) {
                Rcd rcd = queue_back.poll();
                if (!map_back.containsKey(rcd.now)) {
                    map_back.put(rcd.now, rcd.list);
                    for (Integer j : route[rcd.now]) {
                        if (!map_back.containsKey(j)) {
                            List<Integer> list = new ArrayList<>(rcd.list);
                            list.add(j);
                            queue_back.add(new Rcd(j, list));
                        }
                    }
                }
                if (map_front.containsKey(rcd.now)) {
                    mid = rcd.now;
                    break label;
                }
               
            }
        }

        // 组装结果
        if (mid != -1) {
            List<Integer> list = map_front.get(mid);
            for (Integer integer : list) {
                ans.add(wordList.get(integer));
            }
            list = map_back.get(mid);
            for (int i = list.size() - 2; i >= 0; i--) {
                ans.add(wordList.get(list.get(i)));
            }
        }
        return ans;
    }

    // 连通性判断
    private boolean diffOne(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) diff++;
        }
        return diff == 1;
    }

    class Rcd {
        int now;
        List<Integer> list;

        public Rcd(int now, List<Integer> list) {
            this.now = now;
            this.list = list;
        }
    }
}
```
