### 解题思路
此处撰写解题思路

1 对数组进行排序；
2 前一个数组的最后一元素如果等于或者大于，下一个数组的第一个元素，则可以合并；
3 选择Stack，栈顶作为用于比较的元素。

### 代码

```java
class Solution {

    static Comparator comparator = new Comparator<int[]>() {
        public int compare(int[] a, int[] b) {
            if (a[0] == b[0]) {
                return a[1] - b[1];
            } else {
                return a[0] - b[0];
            }
        }
    };

public static int[][] merge(int[][] intervals) {
        if ((null == intervals) || (intervals.length == 0) ) 
            return new int[0][0];

        Arrays.sort(intervals, comparator);

        Stack<Integer> stack = new Stack<>();

        stack.push(intervals[0][0]);
        stack.push(intervals[0][1]);

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] > stack.peek()) {
                stack.push(intervals[i][0]);
                stack.push(intervals[i][1]);
            } else if (intervals[i][1] > stack.peek()) {
                stack.pop();
                stack.push(intervals[i][1]);
            }
        }

        int arrSize = stack.size() / 2;
        int[][] result = new int[arrSize][2];
        int x = 0;

        while (!stack.isEmpty()) {
            result[x][1] = stack.pop();
            result[x][0] = stack.pop();
            x++;
        }
        Arrays.sort(result, comparator);

        return result;
    }
}
```