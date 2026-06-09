## 思路

* 桶思想，每个桶固定大小为 n+1（除最后一个桶之外），这样可以确保相同的任务可以分在不同的桶中
* 当然，每个任务在桶中的次序是固定的，比如说 A 在桶底，那么在每个桶中 A 都在底部，这样可以确保相同任务的间隔时间都不小于 n
* 桶的数量由 拥有最多任务数的那个任务决定，只要他保证了冷却时间，其他的一定可以
* 结果就是 ***(n+1) \* (count - 1) + 最后一个桶的大小***，count 为桶的数量，因为最后一个桶无需固定大小
* ***count*** 很好求，那最后一个桶大小如何求呢，很明显就是 ***拥有最多数任务的个数***，比如**AAABBBCCCDDEE**，那最后一个桶的大小就是 3，因为 A B C 都是拥有 3 个任务数
* 如果冷却时间过短，任务数过多，也就是说桶不够用了，比如说 **AAABBBCCCDDEE** 且 n = 2 这种情况，此时 桶的大小为 3，桶的数量为 3。第一个桶 ABC ，第二个 ABC，第三个 ABC，此时的 D 和 E 我们可以理解为按照``一定次序``放在``桶之上``就行 ，也就是不用放到桶中，这样不会影响桶内元素
* 由于 D 和 E 的出现次数是一定小于桶的数量的，所以最多每个桶上放一个相同任务，这样 D 和 E 按次序排布是一定符合要求的
* 此时的答案就是 ***任务总数*** 了，因为所有的桶都满了，并且多出来的也是任务，没有待命时间
* 故答案就是 两个时间 的最大值

## 代码

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        HashMap<Character, Integer> task_map = new HashMap<>();
        // 记录 单个任务出现的最多的次数
        int max_count = 0;
        // 记录 有最多任务数的 任务个数
        int difference = 0;
        for (Character task : tasks) {
            int count = task_map.getOrDefault(task, 0) + 1;
            task_map.put(task, count);
            max_count = Math.max(max_count,count);
        }
        for(Map.Entry<Character, Integer> entry:task_map.entrySet()){
            if(entry.getValue() == max_count) difference++;
        }
        int number1 = (n + 1) * (max_count - 1) + difference;
        int number2 = tasks.length;
        return Math.max(number1,number2);
    }
}
```

## 参考

[桶思想-简洁高效](https://leetcode-cn.com/problems/task-scheduler/solution/tong-si-xiang-jian-ji-gao-xiao-by-hzhu212/)