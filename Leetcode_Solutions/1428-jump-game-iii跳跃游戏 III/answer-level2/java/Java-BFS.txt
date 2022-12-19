# 代码
```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        int len = arr.length, size = 1;
        boolean[] selected = new boolean[len];
        LinkedList<Integer> queue = new LinkedList<>();
        queue.addLast(start);
        selected[start] = true;
        while (size > 0) {
            while (--size > -1) {
                int cur_position = queue.removeFirst();
                int num = arr[cur_position];
                if (num == 0) return true;
                //左跳
                cur_position -= num;
                if (cur_position > -1 && !selected[cur_position]) {
                    queue.addLast(cur_position);
                    selected[cur_position] = true;
                }
                //右跳
                cur_position += (num << 1);
                if (cur_position < len && !selected[cur_position]) {
                    queue.addLast(cur_position);
                    selected[cur_position] = true;
                }
            }
            size = queue.size();
        }
        return false;
    }
}
```
