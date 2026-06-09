## 思路
建立一个线段树，如果插入的数据和当前有重叠，则返回false。否则，根据其大小选择对左侧还是右侧递归，并注意在为null的时候进行插入（类似BST)。


## 代码
```java
class  Node{
    int start;
    int end;
    Node left;
    Node right;
    public  Node(int s,int e){
        start=s;
        end=e;
    }
}
Node root;
public MyCalendar() {
    
}
    
public boolean book(int start, int end) {
    if(root==null){
        root=new Node(start,end);
        return true;
    }
    return book(root,start,end);
}

private boolean book(Node root, int start, int end) {
    if(end<=root.start){
        if(root.left==null){
            root.left=new Node(start,end);
            return true;
        }
        return book(root.left,start,end);
    }
    if(start>=root.end){
        if ((root.right)==null){
            root.right=new Node(start,end);
            return true;
        }else {
            return book(root.right,start,end);
        }
    }
    return false;
}
```