**思路**
常规深搜解法。这里要注意的两点是，
1. 一个位置只要跳过一次就好，用一个**visited**数组来标记；
2. 找到0之后就不要继续递归了，直接一层层返回就好。

```java
public class Problem03 {

    private int[] arr;
    private int len;
    private boolean[] visited;

    private boolean backTrack(int from) {
        if (from < 0 || from >= len || visited[from]) {
            return false;
        }

        if (arr[from] == 0) {
            return true;
        }

        visited[from] = true;
        return backTrack(from + arr[from]) || backTrack(from - arr[from]);
    }

    public boolean canReach(int[] arr, int start) {
        this.arr = arr;
        len = arr.length;
        visited = new boolean[len];
        return backTrack(start);
    }

}
```
**复杂度分析：**
时间复杂度：$O(n)$。因为定义了一个visited数组，因此每个元素最多只会被访问一次。因此最多访问n次。
空间复杂度：$O(n)$。包括递归的深度以及visited数组都是n量级的。