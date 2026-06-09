### 解题思路
* 方案一、倒排序
* 方案二、优先队列法

### 代码

```java []
// 方案一、倒排序，动态减少
class Solution {
    public int leastInterval(char[] tasks, int n) {
        assert tasks.length >=1 && tasks.length <= 10000;
        assert n >= 0 && n <= 100;
        /*
          int[] map = new int[26];
        for (char c: tasks)
            map[c - 'A']++;
        Arrays.sort(map);
        int time = 0;
        while (map[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (map[25] == 0)
                    break;
                if (i < 26 && map[25 - i] > 0)
                    map[25 - i]--;
                time++;
                i++;
            }
            Arrays.sort(map);
        }
        return time;
        */
        
        int[] taskCounts = new int[26];
        for (char task:tasks) {
            taskCounts[task - 'A']++;
        }
        Arrays.sort(taskCounts);
        // 最短时间
        int time = 0;
        // 每次总是去取最后一个任务元素
        while (taskCounts[25] > 0) {
            int i = 0;
            //在n个冷却时间内安排不同的任务
            while( i <= n) {
                if(taskCounts[25] == 0) {
                    // 最后一个元素没有任务了就停止
                    break;
                }
                if (i < 26 && taskCounts[25 - i] > 0) {
                    taskCounts[25 - i]--;
                }
                time++;
                i++;
            }
            // 总是把最大顺序放到最后一个位置
            Arrays.sort(taskCounts);
        }
         return time;
    }
}
```
```java []
//方案二、优先队列
class Solution {
    public int leastInterval(char[] tasks, int n) {
        assert tasks.length >=1 && tasks.length <= 10000;
        assert n >= 0 && n <= 100;
        int[] taskCounts = new int[26];
        for (char taskFlag: tasks) {
            taskCounts[taskFlag - 'A']++;
        }
        PriorityQueue <Integer> queue = new PriorityQueue <> (26, Collections.reverseOrder());
        for (int taskCount: taskCounts) {
            if (taskCount > 0) {
                queue.add(taskCount);
            }
        }
        int time = 0;
        while (!queue.isEmpty()) {
            int i = 0;
            List <Integer> tempTaskCounts = new ArrayList<> ();
            while (i <= n) {
                if (!queue.isEmpty()) {
                    if (queue.peek() > 1)
                        tempTaskCounts.add(queue.poll() - 1);
                    else
                        queue.poll();
                }
                time++;
                if (queue.isEmpty() && tempTaskCounts.size() == 0)
                    break;
                i++;
            }
            for (int task: tempTaskCounts) {
                queue.add(task);
            }
        }
        return time;
    }
}
```