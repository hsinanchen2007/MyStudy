```
public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
    List<Integer>[] subs = new List[n];
    for (int i = 0; i < subs.length; i++) {
        subs[i] = new ArrayList<>();
    }
    for (int i = 0; i < manager.length; i++) {
        if (manager[i] != -1) {
            subs[manager[i]].add(i);
        }
    }
    //每个员工收到通知的时间
    int[] timeInformed = new int[n];
    Queue<Integer> queue = new ArrayDeque<>();
    queue.offer(headID);
    while (!queue.isEmpty()) {
        int parent = queue.remove();
        for (int child : subs[parent]) {
            //下属收到通知的时间=上级收到通知的时间+上级通知下属所需时间
            timeInformed[child] = timeInformed[parent] + informTime[parent];
            queue.offer(child);
        }
    }
    //最晚收到通知员工收到通知的时间就是总时间
    return Arrays.stream(timeInformed).max().getAsInt();
}
```
