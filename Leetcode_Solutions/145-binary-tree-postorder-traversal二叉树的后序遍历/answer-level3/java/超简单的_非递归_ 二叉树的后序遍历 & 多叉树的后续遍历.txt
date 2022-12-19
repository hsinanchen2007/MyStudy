本算法主要从递归的算法入手，手动模拟程序在执行的时候，计算机执行递归的步骤实现
# 从递归算法谈起
下面算法是后续遍历的递归形式
```
public class Solution {

    public List<Integer> postorderTraversal(TreeNode root) {
        return dfs(root, new ArrayList<>());
    }

    private List<Integer> dfs(TreeNode root, ArrayList<Integer> result) {
        if (root == null) {
            return result;
        }
        
        dfs(root.left, result);
        dfs(root.right, result);
        
        result.add(root.val);
        
        return result;
    }
}
```
上面这段递归代码相信大家只要通过了数据结构课程的期末考试，应该都没有问题，接下来我们从这段递归代码入手，观察程序是怎么运行的。
# 程序方法调用通过压栈的方式执行
我们的计算机在进入每一个方法是，会在该线程方法栈中，为每一个方法生产一部分空间，包括入口参数，包括出口等信息，下图展示了程序的执行过程
```
二叉树结构             1
                     /  \
                    2    3  
                   / \    \
                  4   5    6
                     / 
                   7
```
## 递归方法dfs开始执行：

1、此时第一次执行递归方法dfs，方法的参数node.val=1

![image.png](https://pic.leetcode-cn.com/ad6a1ae25029419ac50285bd5ce352fce246abb89741bed8de53e421c393672a-image.png)

2、当方法执行到方法里面的第一个递归调用dfs(root.left, result)时，方法开始进入第二个栈帧中（也是dfs方法）

![image.png](https://pic.leetcode-cn.com/a3a7f193379c08a3ec371418e5b8cb4569af5a3db6de5a2b4eccaec4f3da2995-image.png)

3、以此类推，当进入到参数是node.val=4的方法时，如果再向里面进行递归一层（参数是node.left = null）时，则会进入递归的出口

![image.png](https://pic.leetcode-cn.com/90bff99433e7cc4af4559d87c8d2e723c60cd7f98a584f79bf3f03383fff2fe8-image.png)

```
    // 递归方法的出口
    public List<Integer> postorderTraversal(TreeNode root) {
        return dfs(root, new ArrayList<>());
    }
```
此时方法会返回，这时候，计算机会为我们返回上一次调用这个递归方法的行数，并继续执行下一行
```
        dfs(root.right, result);
```

如上面的树结构所示，4节点的right同样是null，所以同样会返回到上一层的调用，并执行下一行
```
        result.add(root.val);
```
这样会把结果放入数组result中，并返回上一层迭代，也就是node.val = 2的一层并执行上一层的下一行代码
 
![image.png](https://pic.leetcode-cn.com/a3a7f193379c08a3ec371418e5b8cb4569af5a3db6de5a2b4eccaec4f3da2995-image.png)

```
        dfs(root.right, result);
```
这样，node.val = 5的方法会被加入到栈中

![image.png](https://pic.leetcode-cn.com/8399609c69034b96041222471db58acfb8f0b10b4f459eb6b5cf01ab87f55d8e-image.png)

继续往下执行，直到所有的节点入栈并出栈，计算机就可以完成全部的遍历，并返回result列表作为最终的结果。

# 手动模拟该过程
我们可以手动模拟这个过程，来实现我们的非递归方法
#### 一个难点在于我们如何记录我们的执行情况，也就是如何记录节点的子节点的遍历情况？
我们可以采取再加入一个辅助栈的方式，记录我们当前节点的子节点的出入栈情况

![image.png](https://pic.leetcode-cn.com/87f494e8b77ad423c0b3f2199b5c472d553fe0bf839403681823e490f88204a5-image.png)

我们加入一个状态栈，表示当前节点的遍历情况，其中0表示还未遍历子节点，1表示左节点已经遍历完成，2表示右节点已经遍历完成，可以出栈并将值放入结果列表中

下面是代码
```
    public List<Integer> postorderTraversal(TreeNode root) {

        // 为空直接返回
        if (root == null) {
            return new ArrayList<>();
        }

        // 1、初始化两个栈，分别为数据栈和状态栈
        Deque<TreeNode> stack = new ArrayDeque<>();
        Deque<Integer> log = new ArrayDeque<>();

        List<Integer> result = new ArrayList<>();

        // 2、初始化头结点
        stack.addFirst(root);
        log.addFirst(0);

        // 3当存在数据为进行遍历时，循环遍历
        while (!stack.isEmpty()) {

            // 4、查询当前待遍历节点的及其状态，根据不同的状态，进行不同的操作
            TreeNode node = stack.getFirst();
            int status = log.getFirst();

            switch (status) {
                
                // 5、已经遍历过右节点，可以返回并加入结果集
                case 2 : {
                    stack.removeFirst();
                    log.removeFirst();
                    result.add(node.val);
                    continue;
                }

                // 5、尚未遍历子树，将左子树压入栈，执行遍历左子树的方法
                case 0 : {
                    if (node.left != null) {
                        stack.addFirst(node.left);
                        log.removeFirst();
                        log.addFirst(1);
                        log.addFirst(0);
                    } else {
                        log.removeFirst();
                        log.addFirst(status + 1);
                    }
                    continue;
                }

                // 5、已经遍历左子树，尚未遍历右子树，将右子树压入栈，执行遍历右子树的方法
                case  1 : {
                    if (node.right != null) {
                        stack.addFirst(node.right);
                        log.removeFirst();
                        log.addFirst(2);
                        log.addFirst(0);
                    } else {
                        log.removeFirst();
                        log.addFirst(status + 1);
                    }
                    continue;
                }
            }
        }

        // 6、未存在未遍历的节点，遍历完成，返回结果集
        return result;
    }
```
    该方法思想简单，比两个栈出栈入栈的方法好理解，更重要的是，该方法的思想是模拟计算机执行的操作，可以在面试的时候，推导出来。更重要的是，该方法同样适用多叉树的非递归后续遍历。



