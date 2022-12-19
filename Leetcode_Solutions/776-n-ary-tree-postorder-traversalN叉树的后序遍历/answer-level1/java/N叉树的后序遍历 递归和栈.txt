### 解题思路
此处撰写解题思路

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
    //递归
    public List<Integer> postorder(Node root) {
        List<Integer> result=new ArrayList();
        postorder(root,result);
        return result;
    }
    private void postorder(Node root,List<Integer> result){
        if(root==null){
            return;
        }
        List<Node> list=root.children;
        //遍历所有孩子节点,进行递归
        for(Node node:list){
            postorder(node,result);
        }
        result.add(root.val);
    }
    //使用栈
    public List<Integer> postorder(Node root){
        LinkedList<Integer> result=new LinkedList<>();
        if(root==null){
            return result;
        }
        Stack<Node> stack=new Stack();
        stack.push(root);
        while(!stack.isEmpty()){
            Node node=stack.pop();
            //添加到头部
            result.addFirst(node.val);
            //遍历所用孩子节点放入栈中
            for(Node n:node.children){
                stack.push(n);
            }
        }
        return result;
    }

```