// ### 解法

// ```java
public class CustomStack {
    private int[] aux;
    private int n;
    public CustomStack(int maxSize) {
        aux = new int[maxSize];
        n = 0;
    }

    public void push(int x) {
        if(n == aux.length)
            return;
        aux[n++] = x;
    }

    public int pop() {
        if(n == 0) return -1;
        return aux[--n];
    }

    public void increment(int k, int val) {
        int boundary = Math.min(k, n);
        for(int i = 0; i < boundary; i++)
            aux[i] += val;
    }
}
// ```

// 思路分析：

// * 设计一个栈，并且明确了这个栈的元素个数是有一个最大值的。参考[LeetCode155.最小栈](https://github.com/ustcyyw/yyw_algorithm/blob/master/easy/StackAndQueue/MinStack155.md)的实现思路。链表与数组中选择一个实现：因为本题设定了元素个数的最多为`maxSize`，所以选择数组实现不再需要付出改变数组大小的成本。
// * 数组的实现，关键就是栈顶元素索引的表示。这里使用元素个数`n`去想办法表示，当栈中有一个元素时`n=1`。而栈顶元素为`aux[0]`，所以栈顶元素均用`aux[n-1]`表示。元素入栈时`aux[n]`是没有存放元素的，入栈后栈的元素数量需要加一，所以入栈可以写为` aux[n++] = x;`出栈时，`n--`就使得当前栈顶访问不到，达到删除效果。
// * 对于出栈与入栈操作，时间复杂度都是$O(1)$。对于增加操作，依据题意，将栈底的`k`个元素增加`val`，如果栈中元素少于`k`个，就将所有元素都进行增加。依照`n`与索引的关系，改变的元素的索引从0开始截止`Math.min(k, n)-1`，进行单层遍历。时间复杂度是线性的。

// 运行结果：

// * 难度 medium 7 ms

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖