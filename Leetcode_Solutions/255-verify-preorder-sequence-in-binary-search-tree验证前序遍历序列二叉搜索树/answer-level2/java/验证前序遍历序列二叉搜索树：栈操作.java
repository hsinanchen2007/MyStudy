### 题解思路
1. 对应二叉搜索树来说，左子树最大值小于根节点的值，根节点的值小于右子树的最小值
2. 前序遍历二叉搜索树：按照左中右的思路，会出现数据先递减到左子树最小值，然后数据递增，之后又递减的情况
3. 在出现递增的时候，我们应该更新一个阈值，表示接下来出现的数都不会比该值小，这个值表示右子树的起点
    * 当出现增大的时候说明已经开始遍历右节点，但是这个右节点应该放在哪呢？**最后一个比它小的位置，假定该值为 a**
    * 这样说明另一个问题，在接下来的值中不能出现比这个值a 更小的值了
```
public boolean verifyPreorder(int[] preorder) {
    if (preorder.length == 0) {
        return true;
    }
    Stack<Integer> stack = new Stack<>();
    int currentMaxValue = Integer.MIN_VALUE;
    for (int value : preorder) {
        if (value < currentMaxValue) {
            return false;
        }
        /// 找到最后一个比 val 小的元素，这个值即为 val 的根节点，同时记录该根节点值，后面的值不能比该值小
        while (!stack.isEmpty() && value > stack.peek()) {
            currentMaxValue = stack.pop();
        }
        stack.push(value);
    }
    return true;
}
```