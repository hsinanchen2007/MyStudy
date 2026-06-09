### 解题思路
此处撰写解题思路
要先把每个员工的直属下属找到，并存起来，不然的话，最后从manager中去找的话会超时
### 代码

```java
class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        Queue<Integer> queue = new LinkedList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();
        List<Integer> l = new ArrayList<>();
        l.add(headID);
        map.put(-1, l);
        for (int i = 0; i < manager.length; i++) {
            if (!map.containsKey(manager[i])) {
                List<Integer> t = new ArrayList<>();
                t.add(i);
                map.put(manager[i], t);
            } else {
                List<Integer> temp = map.get(manager[i]);
                temp.add(i);
                map.put(manager[i], temp);
            }
        }
        queue.add(headID);
        int[] ret = new int[n];
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int head = queue.poll();
                List<Integer> sons = map.get(head);
                if (sons != null) {
                    for (int j = 0; j < sons.size(); j++) {
                        int son = sons.get(j);
                        queue.add(son);
                        ret[son] = informTime[head] + ret[head];
                    }
                }
            }
        }
        int maxTime = 0;
        for (int i = 0; i < ret.length; i++) {
            if (ret[i] > maxTime) maxTime = ret[i];
        }
        return maxTime;
    }
}
```