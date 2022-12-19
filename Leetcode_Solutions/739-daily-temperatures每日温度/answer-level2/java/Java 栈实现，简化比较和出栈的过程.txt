### 解题思路
正序遍历温度数组。
使用栈保存温度数组的下标值，下标的差值就是升温天数。
如果当前温度大于栈顶温度，表示栈顶的温度升温天数计算完成，出栈并和下一个栈顶的温度比较。

最终留在栈中的表示升温天数无法计算，默认为 int 数组初始化时候的 0

### 代码
```java
class Solution {

    public int[] dailyTemperatures(int[] T) {
        final Deque<Integer> deque = new LinkedList<>();
        int[] r = new int[T.length]; // 返回最终结果
        for(int i = 0;i < T.length ; i++){ // 正序遍历温度数组
            // 如果当前队列不为空，且当前温度大于栈顶中的温度，设置栈顶升温天数并出栈
            while(!deque.isEmpty() && T[i] > T[deque.peek()]) r[deque.peek()] = i - deque.pop() ;
            deque.push(i); // 当前计算后的温度下标入栈
        }
        return r;
    }
}
```