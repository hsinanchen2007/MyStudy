我们思考一下前序遍历和后序遍历之间的关系：
前序遍历顺序为：根 -> 左 -> 右
后序遍历顺序为：左 -> 右 -> 根
如果1： 我们将前序遍历中节点插入结果链表尾部的逻辑，修改为将节点插入结果链表的头部
那么结果链表就变为了：右 -> 左 -> 根
如果2： 我们将遍历的顺序由从左到右修改为从右到左，配合如果1
那么结果链表就变为了：左 -> 右 -> 根
这刚好是后序遍历的顺序

基于这两个思路，我们想一下如何处理：
    修改前序遍历代码中，节点写入结果链表的代码，将插入队尾修改为插入队首
    修改前序遍历代码中，每次先查看左节点再查看右节点的逻辑，变为先查看右节点再查看左节点

首先看一下二叉树的后序遍历迭代的写法：
后序 = 前序 + 逆序
```
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {

        Stack<TreeNode> stack = new Stack<>();
        //重要：使用LinkedList，因为其可以在前添加，进行添加逆序
        LinkedList<Integer> res = new LinkedList<>();

        if(root == null){
            return res;
        }

        stack.push(root);

        while(!stack.isEmpty()){

            TreeNode tmp = stack.pop();
            //前序 + 逆序 = 后序  ==> 这里只是把前序的add缓存addFirst
            res.addFirst(tmp.val);


            /*
                注意：上面说到，应该把右，左，根 进行逆序，
                但是下面的操作时用的栈，先把左进栈，右后进栈，所以弹出的先是右，后是左

                一直压栈，而不是等栈的size为空再进行，所以还是dfs，而不是层次，只不过形式有点像
                这里用的是栈，层次用的是队列
            */
            if(tmp.left != null){
                stack.push(tmp.left);
            }

            if(tmp.right != null){
                stack.push(tmp.right);
            }

        }
        return res;
    }
}
```

对上面的代码稍微修改，即得到n叉树的代码：
```
class Solution {
    public List<Integer> postorder(Node root) {
        Stack<Node> stack = new Stack<>();
        LinkedList<Integer> res = new LinkedList<>();

        if(root == null){
            return res;
        }

        stack.push(root);

        while(!stack.isEmpty()){

            Node tmp = stack.pop();

            res.addFirst(tmp.val);

            for(int i=0; i<tmp.children.size(); i++){
                stack.push(tmp.children.get(i));
            }
        }
        return res;
        
    }
}
```


