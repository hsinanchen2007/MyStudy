# 内存消耗和执行时间均打败100%
![image.png](https://pic.leetcode-cn.com/aac39e8d93faaea5737cd26fea8c0fa1c2bc64118b9c6f0723cd7341760473ad-image.png)

# 三步简单易懂
## 一、复制每一个节点，使得复制后的节点都在当前节点的下一个节点
```
//拷贝链表
    private void copy(Node head){
        while(head!=null){
            Node cloneNode = new Node(head.val);
            Node nextNode = head.next;
            head.next = cloneNode;
            cloneNode.next = nextNode;
            head = cloneNode.next;
        }
    }
```
## 二、原生链表的节点的指向任意节点，使复制的节点也都指向某一任意节点
```
//指定随机指针
    private void randomDirect(Node head){
        while(head!=null){
            Node cloneNode = head.next;
            if(head.random!=null){
                Node direct = head.random;
                cloneNode.random = direct.next;
            }
            head = cloneNode.next;
        }
    }
```
## 三、重新连接节点，把原生节点重新连接起来，把克隆后的节点连接起来
```
//重新连接 链表
    private Node reList(Node head){
        Node cloneNode = head.next;
        Node cloneHead = cloneNode;
        head.next = cloneNode.next;
        head = head.next;
        while(head!=null){
            cloneNode.next = head.next;
            head.next = head.next.next;
            head = head.next;
            cloneNode = cloneNode.next;
        }
        return cloneHead;
    }
```
## 图片展示总结
![图解 (2).png](https://pic.leetcode-cn.com/7a70fbac7677a9a1cd31d404a0ad2d9dc3d92ead30b5e741bb2459dea2077523-%E5%9B%BE%E8%A7%A3%20\(2\).png)

## 完整代码展示：
```
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {
        if(head==null){
            return null;
        }
        copy(head);
        randomDirect(head);
        return reList(head);
    }
    //拷贝链表
    private void copy(Node head){
        while(head!=null){
            Node cloneNode = new Node(head.val);
            Node nextNode = head.next;
            head.next = cloneNode;
            cloneNode.next = nextNode;
            head = cloneNode.next;
        }
    }
    //指定随机指针
    private void randomDirect(Node head){
        while(head!=null){
            Node cloneNode = head.next;
            if(head.random!=null){
                Node direct = head.random;
                cloneNode.random = direct.next;
            }
            head = cloneNode.next;
        }
    }
    //重新连接 链表
    private Node reList(Node head){
        Node cloneNode = head.next;
        Node cloneHead = cloneNode;
        head.next = cloneNode.next;
        head = head.next;
        while(head!=null){
            cloneNode.next = head.next;
            head.next = head.next.next;
            head = head.next;
            cloneNode = cloneNode.next;
        }
        return cloneHead;
    }
}
```