### 解题思路
代码和思路就是官方第二个，补充一点自己的理解。

在整个温度表中，有价值的就是1.最高的T；2.在上升途中的T。
从右边开始遍历，保留最高T和还在上升的T。
对于每个T来说，右侧的比它低的T是无意义的，因为求它左侧的元素的上升天数时是不需要这些值的，对于它自己来说，它只需要知道后边的比他大的第一个元素的坐标就够了，故在入栈前检查栈内元素，把栈顶比它小的元素全部出栈，此时栈顶的位置元素就是它需要达到的位置。
另外，要先计算res[i]的值，再把最新的上升元素入栈，不然不成自己减自己了么。

### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        Stack<Integer> s = new Stack<>();

        for (int i = T.length - 1; i >= 0; i--) {
            while (!s.isEmpty() && T[i] >= T[s.peek()])
                s.pop();
            res[i] = s.isEmpty() ? 0 : s.peek() - i;
            s.push(i);
        }

        return res;
    }
}
```