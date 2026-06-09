使用广度优先搜索。从`start`点开始，每次取往左和往右的两个位置进行下一次访问，并标记访问过的位置。如果访问到元素为0的位置，则返回`true`。如果所有可访问的位置都已经访问过，仍未访问到元素为0的位置，则返回`false`。
```
class Solution {
    public boolean canReach(int[] arr, int start) {
        int length = arr.length;
        boolean[] canReach = new boolean[length];
        canReach[start] = true;
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.offer(start);
        while (!queue.isEmpty()) {
            int index = queue.poll();
            int step = arr[index];
            int left = index - step, right = index + step;
            if (left >= 0) {
                if (arr[left] == 0)
                    return true;
                else if (!canReach[left]) {
                    canReach[left] = true;
                    queue.offer(left);
                }
            }
            if (right < length) {
                if (arr[right] == 0)
                    return true;
                else if (!canReach[right]) {
                    canReach[right] = true;
                    queue.offer(right);
                }
            }
        }
        return false;
    }
}
```
