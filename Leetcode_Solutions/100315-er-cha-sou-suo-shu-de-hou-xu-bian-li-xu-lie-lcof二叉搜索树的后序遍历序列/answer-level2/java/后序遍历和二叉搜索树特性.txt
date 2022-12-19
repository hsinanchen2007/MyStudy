### 解题思路
通过最后一个元素 ，也就是根，划分左右子树 左子树小于根，右子树大于根
如果能清晰划分则然后左右子树递归下去

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        int n = postorder.length;
        if (n == 0 || n == 1) return true;
        return verifyPostorder(postorder, 0, n-1);
    }
    // 闭区间
    boolean verifyPostorder(int[] postorder, int st, int end) {
        if (st >= end) return true; //1个或0个元素时
        int root = postorder[end];
        int ri = st;
        while (postorder[ri] < root) {
            ri++; //找到左子树的第一个
        }
        // 判断右子树符合
        for (int i=ri;i<end;i++) {
            if (postorder[i]<=root){
                return false;
            }
        }
        return verifyPostorder(postorder, st, ri-1) && verifyPostorder(postorder, ri, end-1);
    }
}
```
![image.png](https://pic.leetcode-cn.com/ddd4a18a9329bc653b38a1d5ad79c84353a2ce0dadafe1599d09200215e8025b-image.png)
