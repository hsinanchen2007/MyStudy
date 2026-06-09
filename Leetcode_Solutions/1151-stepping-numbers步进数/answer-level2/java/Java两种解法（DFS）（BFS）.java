
### 解法一、DFS
- 一开始想到的是先把所有步进数求出来放到一个集合，然后再遍历取其中`>=low && <= high`的数添加到结果集合 result，最后排下序。
- 求步进数是用 DFS 的方法，以 1 到 9 开头，每次把当前数乘 10 加上个位数加 1 或减 1。注意一下个位为 0 和 9 的特殊情况就好。
- 0 特殊处理。

代码：

```java
class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        List<Integer> list = new ArrayList<>();
        list.add(0);
        for (int i = 1; i <= 9; i++) {
            dfs(list, i);
        }
        List<Integer> result = new ArrayList<>();
        for (int num : list) {
            if (num >= low && num <= high) {
                result.add(num);
            }
        }
        Collections.sort(result);
        return result;
    }

    public void dfs(List<Integer> list, int cur) {
        list.add(cur);
        if (cur > Integer.MAX_VALUE / 10) {
            return;
        }
        int r = cur % 10;
        if (r != 9) {
            dfs(list, cur * 10 + r + 1);
        }
        if (r != 0) {
            dfs(list, cur * 10 + r - 1);
        }
    }
}
```

- 可以不求出所有结果，只在小于 high 范围内递归，在 DFS 过程中只添加符合要求的结果。

代码：

```java
class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        List<Integer> result = new ArrayList<>();
        if (low == 0) {
            result.add(0);
        }
        for (int i = 1; i <= 9; i++) {
            dfs(result, i, low, high);
        }
        Collections.sort(result);
        return result;
    }

    public void dfs(List<Integer> result, int cur, int low, int high) {
        if (cur >= low && cur <= high) {
            result.add(cur);
        }
        if (cur > high / 10) {
            return;
        }
        int r = cur % 10;
        if (r != 9 && cur * 10 + r + 1 <= high) {
            dfs(result, cur * 10 + r + 1, low, high);
        }
        if (r != 0 && cur * 10 + r - 1 <= high) {
            dfs(result, cur * 10 + r - 1, low, high);
        }
    }
}
```

### 解法二、BFS

- 先把 1 到 9 添加到队列，然后每次取出队列中的数，符合要求就添加到结果集合 result，并把下一位范围内的步进数加到队列。

代码：

```java
class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        Queue<Integer> queue = new LinkedList<>();
        List<Integer> result = new ArrayList<>();
        if (low == 0) {
            result.add(0);
        }
        for (int i = 1; i <= 9; i++) {
            queue.offer(i);
        }
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            if (cur >= low && cur <= high) {
                result.add(cur);
            }
            if (cur > high / 10) {
                continue;
            }
            int r = cur % 10;
            if (r != 9 && cur * 10 + r + 1 <= high) {
                queue.offer(cur * 10 + r + 1);
            }
            if (r != 0 && cur * 10 + r - 1 <= high) {
                queue.offer(cur * 10 + r - 1);
            }
        }
        Collections.sort(result);
        return result;
    }
}
```

