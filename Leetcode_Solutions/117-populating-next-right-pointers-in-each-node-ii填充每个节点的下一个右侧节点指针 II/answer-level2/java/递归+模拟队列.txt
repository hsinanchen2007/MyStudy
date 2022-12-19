### 方法一：递归
递归的话，我们对于一个节点的左右节点分开来考虑
首先对于某个节点的左节点，有三种情况：
1. 左节点为空，什么也不用做
![image.png](https://pic.leetcode-cn.com/e9cbae19ff5ec7b37ceacceacc185da588f6b7eb03ea2a3dee513d8700852d50-image.png)
2. 左节点不为空，右节点为空，此时左节点的next为同层离它最近的那个节点
![image.png](https://pic.leetcode-cn.com/6af4ee5dd68866a5f8864a05d7edc94469a0fb463bdf4fd3fc4fb044e0591d8e-image.png)
3. 左节点不为空，右节点也不为空，此时左节点的next就是右节点
![image.png](https://pic.leetcode-cn.com/142f9a16d8446514f8491bbe030a45edd8e13c8afaaea6e846b622f24e25e836-image.png)
对于某个节点的右节点，就只有两种情况：
1. 右节点为空，什么也不用做
![image.png](https://pic.leetcode-cn.com/3b2a7c06ced721f40cf7957b2a966c3b081c5f1443358ed07f8c89e5185488f5-image.png)
2. 右节点不为空，右节点的next为同层离它最近的节点
![image.png](https://pic.leetcode-cn.com/c9e85d96532b091578d7a039dfe1e8dd71d2954c61e4d194d3a1990b6a89d8dd-image.png)
这里对于寻找与当前的节点同层的最近节点的方法就是先把当前节点的上一层的next都连接好，然后在上一层寻找第一个节点的（左或者右）子节点不为空，就返回，就是离这个节点最近的节点
另外这种方法要注意的是，要先把右子树都连起来再连左子树，假如对于一棵树先连接左子树，如下图所示，
![image.png](https://pic.leetcode-cn.com/2355e9c028ce0cfc089f2c8ab3ee9c1501c17e3f0dc685031ec3051ce342a750-image.png)
被红框框柱的这个点的next根据图中所示会是null，但是如果线连接右子树，图就会变成这样
![image.png](https://pic.leetcode-cn.com/9c8708cc87b9ec3c0c3a497979bb848fb4807f4c59169dbc8d8f54d4cba994ea-image.png)
此时被红框框柱的节点的next就可以正确的赋值，所以这里要先连接好右子树再连接左子树
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    Node findnearestNode(Node node){
        Node res=null;
        while(node!=null){
            if(node.left!=null){
                res=node.left;
                break;
            }
            if(node.right!=null){
                res=node.right;
                break;
            }
            
            node=node.next;
        }
        
        return res;
    }
    
    public Node connect(Node root) {
        if(root==null) return root;
        
        //如果root的左右子树不为空
        if(root.left!=null){
            if(root.right!=null){
                root.left.next=root.right;
            }else{
                root.left.next=findnearestNode(root.next);
            }
        }
        
        if(root.right!=null){
            root.right.next=findnearestNode(root.next);
        }
       
        //把root的右子树都连起来
        connect(root.right);
        
        //把root的左子树都连起来
        connect(root.left);
        
        return root;
    }
}
```
### 方法二  模拟队列
这道题使用队列实现层序遍历肯定是可以解决的，但是题目要求的空间复杂度为常量级别，所以这里使用指针来模拟队列的层序遍历，大体的思路就是一层一层的遍历这颗树，然后在每一层让前一个非空的节点指向后一个非空的节点就好了。
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        
        Node cur=root;
        
        while(cur!=null){
            Node dummy=new Node();
            Node tail=dummy;
            
            while(cur!=null){
                if(cur.left!=null){
                    tail.next=cur.left;
                    tail=tail.next;
                }
                
                if(cur.right!=null){
                    tail.next=cur.right;
                    tail=tail.next;
                }
                
                cur=cur.next;
            }
            
            cur=dummy.next;
        }
        
        return root;
    }
}
```


