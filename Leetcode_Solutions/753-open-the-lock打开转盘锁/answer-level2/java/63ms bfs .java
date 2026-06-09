思路：
1、把问题转化成图的最短路径问题，这里的最短路径指的是由起始状态"0000"转换为目标状态所需要的最少变换次数，
那么就可以用bfs来解决这一类最短路径问题。
2、一次变换能够产生八个新的状态（其实就是题目中的旋转了一下拨轮后的效果）举个例子：
0000 -> 9000 1000 0900 0100 0090 0010 0009 0001
这里的变换注意一下:
1、虽然有四个拨轮，但是每次旋转只能旋转其中一个
```
class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> visited = new HashSet<>();
        Collections.addAll(visited, deadends);
        // 如果deadends包含起始状态"0000"直接返回-1
        if (visited.contains("0000")) {
            return -1;
        }
        LinkedList<String> queue = new LinkedList<>();
        queue.add("0000");
        visited.add("0000");
        int level = -1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            level++;
            for (int i = 0; i < size; i++) {
                String cur = queue.removeFirst();
                if (cur.equals(target)) {
                    return level;
                }
                // 获取下一层能达到的状态注意要越过deadends中包含的
                char[] chars = cur.toCharArray();
                for (int j = 0; j < 4; j++) {
                    char temp = chars[j];
                    chars[j] = (temp == '9' ? '0' : (char) (temp + 1));
                    String next = String.valueOf(chars);
                    if (visited.add(next)) {
                        queue.addLast(next);
                    }
                    chars[j] = (temp == '0' ? '9' : (char) (temp - 1));
                    next = String.valueOf(chars);
                    if (visited.add(next)) {
                        queue.addLast(next);
                    }
                    chars[j] = temp;
                }
            }
        }
        return -1;
    }
}
```

