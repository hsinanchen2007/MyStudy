### 解题思路
![二叉树.png](https://pic.leetcode-cn.com/fb4c569bf73cf9626e471cbd2b821906b2864bdec929193757ef8992bd5168cf-%E4%BA%8C%E5%8F%89%E6%A0%91.png)
申请辅助栈stack：
终止条件为**栈不为空且当前处理的结点不为空**
1.依次将当前处理结点及其左节点加入栈
2.取出栈顶元素ele
3.设置当前处理元素为ele.right
# 栈的过程分析
1. 当前处理结点：1  栈：
2. 当前处理结点：1  栈：1
3. 当前处理结点：2  栈：1 2
4. 当前处理结点：3  栈：1 2 3
5. 当前处理结点：3  栈：1 2  *出栈元素为3，打印*
6. 当前处理结点：3的右孩子（null）  栈：1 2
7. 当前处理结点：2  栈：1  *出栈元素为2，打印*
8. 当前处理结点：2的右孩子4  栈：1
9. 当前处理结点：4  栈：1 4
10. 当前处理结点：4  栈：1   *出栈元素为4，打印*
11. 当前处理结点：4的右孩子null  栈：1
12. 当前处理结点：1  栈：   *出栈元素为1，打印*
13. 当前处理结点：1的右孩子5  栈：5
14. 当前处理结点：5  栈：   *出栈元素为5，打印*
15. 当前处理结点：5的右孩子null  栈：
16. 结束
### 代码

```java
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new LinkedList<Integer>();

        //辅助栈
        Stack<TreeNode> stack = new Stack<TreeNode>();

        TreeNode node = root;//栈顶元素
        while(***node != null || !stack.empty()***){//循环终止条件！！！！！！
            while(node != null){
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();//取出栈顶元素
            ans.add(node.val);            
            node = node.right;
        }

        return ans;
    }
}
```