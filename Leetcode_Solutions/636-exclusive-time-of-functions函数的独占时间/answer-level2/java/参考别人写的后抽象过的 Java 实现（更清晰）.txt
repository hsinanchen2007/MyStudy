### 解题思路
本题关键在如何处理时间间隔，已给出注释，其他应该比较好理解。[参考链接](https://leetcode-cn.com/problems/exclusive-time-of-functions/solution/c-stack-pair-string-by-crossing-2/)
![执行结果](https://pic.leetcode-cn.com/56c582405ba8f549cf8a3644f792725ccbe6ec8455957a623ad5654f770f2b0f-image.png)

### 代码

```java
class Solution {
    class Task {
        int id = 0;
        int time = 0;
        boolean isStart = true;

        Task(String[] split) {
            this.id = Integer.valueOf(split[0]);
            this.time = Integer.valueOf(split[2]);
            this.isStart = split[1].equals("start");
        }
    }

    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Task> stack = new Stack<>();
        int[] ans = new int[n];
        for (String log : logs) {
            Task task = new Task(log.split("\\:"));
            if (task.isStart) {
                stack.push(task);
            } else {
                Task last = stack.pop();
                int duration = task.time - last.time + 1;
                ans[task.id] += duration;
                // 栈若不空，说明之前还有任务没有执行完成，那个任务的执行时间需要减去当前任务的执行时间
                if (!stack.isEmpty()) {
                    ans[stack.peek().id] -= duration;
                }
            }
        }

        return ans;
    }
}
```