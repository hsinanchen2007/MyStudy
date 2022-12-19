这相当于一棵深度为N的完全二叉树. 其中根节点值为0, 在当前行的索引为1.
每一个节点的左子节点值等于当前节点的值, 左子节点所在行的索引等于当前节点索引*2-1.
每一个节点的右子节点值与当前节点的值相反(当前节点值异或1), 右子节点所在行的索引等于当前节点索引*2.

完整代码
```java
class Solution {
    public int kthGrammar(int N, int K) {
        // 从最后一行索引为K的节点开始, 到根节点的路径. 记录下每个节点所在行的索引.
        int[] children = new int[N];
        children[0] = K;
        for (int i = 1; i < children.length; i++) {
            children[i] = (children[i - 1] + 1) / 2;
        }

        int result = 0;
        for (int i = N - 2; i >= 0; i--) {
            if (children[i] == children[i + 1] * 2) {
                result ^= 1;
            }
        }
        return result;
    }
}
```