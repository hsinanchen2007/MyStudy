### 代码

```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        if (arr == null || arr.length == 0 || start >= arr.length) {
            return false;
        }

        boolean[] hasArrived = new boolean[arr.length];

        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(start);

        while (!queue.isEmpty()) {
            int loc = queue.poll();
            if (loc < 0 || loc >= arr.length || hasArrived[loc]) {
                continue;
            }

            if (arr[loc] == 0) {
                return true;
            }

            hasArrived[loc] = true;
            queue.add(loc + arr[loc]);
            queue.add(loc - arr[loc]);
        }

        return false;
    }
}
```