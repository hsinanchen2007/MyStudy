### 解题思路
 对于水壶`X`和`Y`，每次有6种可选操作：
1. 装满`X`
2. 倒空`X`
3. 装满`Y`
4. 倒空`Y`
5. 把`X`里的水倒入`Y`
    * `X`里的水多余`Y`的余量（倒不完）
    * `X`里的水少于`Y`的余量（倒完）
6. 把`Y`里的水倒入`X`
    * `Y`里的水多余`X`的余量（倒不完）
    * `Y`里的水少于`X`的余量（倒完）

 **题目里的坑：**
    1. 存储状态的数组用`byte[][]`会超空间，需要把状态压缩一下，转化为`Long`。
    2. 当`X`和`Y`水壶两个加一起的容量不到`z`时，一定没有解。
 
**复杂度分析**
* 时间复杂度： $O(XY)$
* 空间复杂度： $O(XY)$
* 
一个牛逼的BFS写法，直接算总水量（因为不可能两个杯子都是半满状态，官方给出的解释是“因为观察所有题目中的操作，操作的结果都至少有一个桶是空的或者满的”）。**测了一下，速度能提高5倍多**。
 >[https://leetcode-cn.com/problems/water-and-jug-problem/solution/hu-dan-long-wei-liang-zhang-you-yi-si-de-tu-by-ant/](https://leetcode-cn.com/problems/water-and-jug-problem/solution/hu-dan-long-wei-liang-zhang-you-yi-si-de-tu-by-ant/)

### 代码
``` java
class Solution {
    private Set<Long> marked;
    private Queue<Long> states; 
    private long xCapacity, yCapacity;
    private int z;

    public boolean canMeasureWater(int x, int y, int z) {
        if (x == z || y == z || x + y == z) return true;
        if (x + y < z) return false;
        xCapacity = x + 1;
        yCapacity = y + 1;
        this.z = z;
        marked = new HashSet<Long>();
        states = new LinkedList<Long>();

        int xResidual = 0, yResidual = 0;
        markState(xResidual, yResidual);
        while (!states.isEmpty()) {
            long curState = states.poll();
            xResidual = (int) (curState / yCapacity);
            yResidual = (int) (curState % yCapacity);
            int nextXResidual = xResidual;
            int nextYResidual = yResidual;
            // System.out.println("try state: " + xResidual + ", " + yResidual);

            // 1 X没有水
            if (xResidual == 0) {
                // 1、装满
                nextXResidual = x;
                nextYResidual = yResidual;
                if (markState(nextXResidual, nextYResidual)) return true;
            } else { // 2 X有水
                // 3、清空
                nextXResidual = 0;
                nextYResidual = yResidual;
                if (markState(nextXResidual, nextYResidual)) return true;
            }

            // 3 Y没有水
            if (yResidual == 0) {
                // 装满
                nextXResidual = xResidual;
                nextYResidual = y;
                if (markState(nextXResidual, nextYResidual)) return true;
            } else { // 4 Y有水
                // 清空
                nextXResidual = xResidual;
                nextYResidual = 0;
                if (markState(nextXResidual, nextYResidual)) return true;
            }

            // 5、把Y倒入X
            if (yResidual > 0 && xResidual < x) {
                int moveSize = Math.min(yResidual, x - xResidual);
                nextXResidual = xResidual + moveSize;
                nextYResidual = yResidual - moveSize;
                if (markState(nextXResidual, nextYResidual)) return true;
            }

            // 6、把X倒入Y
            if (xResidual > 0 && yResidual < y) {
                int moveSize = Math.min(xResidual, y-yResidual);
                nextXResidual = xResidual - moveSize;
                nextYResidual = yResidual + moveSize;
                if (markState(nextXResidual, nextYResidual)) return true;
            }
        }
        return false;
    }

    private boolean markState(int xResidual, int yResidual) {
        long id = xResidual * yCapacity + yResidual;
        // System.out.println(id + ": " + xResidual + ", " + yResidual + ", " + z);
        if (!marked.contains(id)){
            marked.add(id);
            states.add(id);
            // System.out.println(id + ": " + xResidual + ", " + yResidual);
            if (xResidual == z || yResidual == z || xResidual + yResidual == z) 
                return true;
        }
        return false;
    }
}
```