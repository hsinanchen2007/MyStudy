![无标题.png](https://pic.leetcode-cn.com/6366540e9d030b646718c851f8b63c47a9c226d9ed6ee350eebbd8733277ea09-%E6%97%A0%E6%A0%87%E9%A2%98.png)

    定义一个boolean类型的数组arrived，表示某下标是否已经到达过；
    再广度优先搜索数组的下一个位置，有两个选择：nextPos0 和 nextPos1，再判断下个位置是否越界，越界了就不必继续搜索对应的下个位置。
    其他的没什么可说的，下看代码：
```
class Solution {
    private boolean[] arrived;

    public boolean canReach(int[] arr, int start) {
        arrived = new boolean[arr.length];
        return bfs(arr, start);
    }

    public boolean bfs(int[] arr, int start) {
        if (arr[start] == 0)
            return true;
        if (arrived[start])
            return false;
        arrived[start] = true;
        int nextPos0 = start - arr[start];
        int nextPos1 = start + arr[start];
        if (nextPos0 >= 0 && nextPos1 < arr.length)
            return bfs(arr, nextPos0) || bfs(arr, nextPos1);
        if (nextPos0 >= 0)
            return bfs(arr, nextPos0);
        if (nextPos1 < arr.length)
            return bfs(arr, nextPos1);
        return false;
    }
}
```
