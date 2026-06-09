### 解题思路
看了别人的做法，基本都是递归加回溯，我是刚开始刷题，想写个非递归的方法，比较耗空间和耗时，但是就是想通过非递归的方式加固下自己对深度广度优先遍历的理解。
主要思路就是因为节点和节点和以及路径是变化的，所以非递归就需要自己用栈去维护每个状态，所以这三个变化的量都用一个栈来存储。这样是可以做出来，但是时间和空间都比较低效，每次都是创建新的list去存路径，好处就是不用回溯去移除某个元素。。。。

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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        Stack stack = new Stack();
        Stack sums = new Stack();
        Stack<List> arrs = new Stack();
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        ArrayList arrayList = new ArrayList();
        arrayList.add(root.val);
        stack.push(root);
        sums.push(root.val);
        arrs.push(arrayList);
        while(!stack.isEmpty()){
            TreeNode curNode = (TreeNode) stack.peek();
            stack.pop();
            int curSum = (int) sums.peek();
            ArrayList curlist = (ArrayList) arrs.peek();
            arrs.pop();
            sums.pop();
            if(curNode.left==null&&curNode.right==null){
                if(curSum == sum){
                    res.add(curlist);
                }
            }
            if(curNode.left!=null){
                stack.push(curNode.left);
                sums.push(curSum+curNode.left.val);
                ArrayList newArr = new ArrayList(curlist);
                newArr.add(curNode.left.val);
                arrs.push(newArr);
            }
            if(curNode.right!=null){
                stack.push(curNode.right);
                sums.push(curSum+curNode.right.val);
                ArrayList newArr = new ArrayList(curlist);
                newArr.add(curNode.right.val);
                arrs.push(newArr);
            }
        }
        return res;
    }
}
```