```
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
```
```
class Solution { //双栈法
    public List<Integer> postorder(Node root) {
        List<Integer> list=new ArrayList<>();//建立一个整数列表，一个节点列表，两个栈
        List<Node> curr=new ArrayList();
        Stack<Node> stack1=new Stack();
        Stack<Node> stack2=new Stack();
        if(root!=null){  //根不空，进栈1
            stack1.push(root);
            while(!stack1.isEmpty()){//栈1不空出栈1，然后进栈2
                
                Node temp=stack1.pop();
                stack2.push(temp);
                curr=temp.children;
            for(int i=0;i<curr.size();i++)//检查出栈节点的孩子依次入栈1
            {    stack1.add(curr.get(i));}        
        }}
        while(!stack2.isEmpty()){//栈2不空依次出栈，值加入列表
            Node ss=stack2.pop();
            list.add(ss.val);
        }
    return list;    //返回列表
    }
}
```
