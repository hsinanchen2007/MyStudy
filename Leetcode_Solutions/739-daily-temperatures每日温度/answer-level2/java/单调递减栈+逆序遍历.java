单调递减栈的性质是可以找到左起第一个比当前数字大的元素
该题是要找出右起第一个比当前数字大的元素，所以就对原始数组逆序遍历，使用单调递减栈
同时为了方便，我们在栈中放置索引，而不是温度值本身

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        Stack<Integer> data = new Stack<>();
        int size = T.length;
        int[] result = new int[size];
        // 逆序遍历
        while(size-- >0) {
            if (data.empty()) {
                // 最右边的温度，此时结果必然是0
                data.push(size);
            } else {
                int val = T[size];
                while(!data.empty()) {
                    // 单调递减栈，栈顶的元素必须大于当前温度
                    if (val < T[data.peek()]) {
                        // 维护之后的新栈顶（当前温度）与次栈顶的索引相减就是结果
                        result[size] = data.peek() - size;
                        break;
                    } else {
                        data.pop();
                    }
                }
                data.push(size);
            }
        }
        return result;
    }
}
```