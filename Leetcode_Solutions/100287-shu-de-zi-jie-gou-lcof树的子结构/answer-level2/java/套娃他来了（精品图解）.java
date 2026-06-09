想不清楚就拿样例比划比划，不要坐那空想。
![image.png](https://pic.leetcode-cn.com/7169792aa0a008f08ef67bf61ee80a1e07cb8843de5a4a70ebb097a2ecfc408d-image.png)

拿题干中的树举例，大脑一眼就能看出确实存在相同的结构（如下图）。
![image.png](https://pic.leetcode-cn.com/659a697eb520e728d9c3141a799dd04e71031359a21f4c129aaa17a409a865fd-image.png)
### **如果要你以程序的角度一步一步来，你会怎么比较？**
首先程序是不知道什么子结构的， 按照题目意思 ，B 是 A 的子结构意味着**从 A 的某个节点往下，有一部分节点和 B 一模一样。**
显然程序也不知道是**从哪个节点**开始开始一模一样的，那只好从根出发慢慢比咯。
![image.png](https://pic.leetcode-cn.com/d65806bc5e3262764c8b6482c16edfb0d98578c34cab9f6ccd1209c0ee4d72a8-image.png)

很显然，根节点就不一样，那说明不是 3 这个节点，这次比较返回了失败。失败没关系，依然有可能是从某个子孙节点开始一模一样的。**于是递归A 树中的节点，比较是不是从该节点开始的某些部分与 B 树一模一样**。首先从 4 开始，很快你一眼就看出这次应该返回成功，如下图。
![image.png](https://pic.leetcode-cn.com/fba80dc5d9f78c89097e961d57f4d83b3607f1458fa9902eb508815c79c83840-image.png)
那这个样例就结束了，答案是 true。
如果我们先把***从 A 中的某个节点开始，比较是不是部分节点和 B 树一模一样这个过程***的实现先放一边的话，那整个递归流程其实很容易就写出来了。
```java
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        //题目强调 B 树为空就不是任意树的子结构，肯定返回返回 false。而如果当前比较的A 树的节点为空，也自然返回 false。
        if(B==null||A==null) return false;
        if(isPartSame(A,B))
            return true;
        else 
            return isSubStructure(A.left,B) || isSubStructure(A.right,B);
    }
```
下面就是 `boolean isPartSame(TreeNode A, TreeNode B)` 这个我们刚刚放一边函数如何实现的问题了。
回到例子中，假设现在递归到了 A 中的 4，很明显 A.val=4,B.val=4 ，这两个节点是一样的没问题，那下面的节点怎么比较？ 这就又需要递归比较了。代码也很简单，如下。

```java
    public boolean isPartSame(TreeNode A, TreeNode B) {
        //注意思考边界条件，整个 B 树是 A 树某个子树的一部分。因此当前 B 树节点为 null  当然是 ok 的。例子见下图
        if(B==null) return true;
        if(A==null) return false;

        if(A.val==B.val)
            return isPartSame(A.left,B.left) && isPartSame(A.right,B.right);
        else 
            return false;
           
    }
```
![image.png](https://pic.leetcode-cn.com/137eaa28e23fcd45e16858ea24b12ac2218fd2d9e9b97bb7256e41546fed66e9-image.png)





最后附上双百代码
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(B==null||A==null) return false;
        if(!isSub(A,B))
            return isSubStructure(A.left,B) || isSubStructure(A.right,B);
        return true;
    }
    public boolean isPartSame(TreeNode A, TreeNode B) {
        if(B==null) return true;
        if(A==null) return false;

        if(A.val==B.val)
            return isPartSame(A.left,B.left) && isPartSame(A.right,B.right);
        else 
            return false;
           
    }
}
```