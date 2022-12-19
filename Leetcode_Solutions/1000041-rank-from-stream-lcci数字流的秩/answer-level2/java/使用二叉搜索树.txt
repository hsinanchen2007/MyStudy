### 解题思路
每个节点有四个属性,val是存进来的x的值,count是小于等于val的节点数,还有其左孩子和右孩子,小于节点val放左边并count+1,大于的放右边且count不变,等于直接该节点count加1就行,查找时,若节点val小于要查找的值,则将该节点的count计入总数,大于则不管.

### 代码

```java
class StreamRank {
    class Node{
        int val;
        int count;
        Node left;
        Node right;
        public Node(int val){
            this.val=val;
            this.count=1;
            this.left=null;
            this.right=null;
        }
    }
    public Node head=null;
    public StreamRank() {

    }
    
    public void track(int x) {
        if(head==null){
            Node node = new Node(x);
            head=node;
        }else{
            Node node = head;
            while(node!=null){
                if(node.val==x){
                    node.count++;break;
                }
                else if(node.val>x){
                    node.count++;
                    if(node.left!=null) {
                    	node=node.left;
                    }else {
                    	node.left=new Node(x);
                    	break;
                    }
                }else{
                	if(node.right!=null) {
                    	node=node.right;
                    }else {
                    	node.right=new Node(x);
                    	break;
                    }
                }
            }
            
        }
    }
    
    public int getRankOfNumber(int x) {
        if(head==null)return 0;
        Node node=head;
        int nums = 0;
        while(node!=null){
        	if(x>node.val){
                nums+=node.count;
                node=node.right;
            }else if(x==node.val){	
                nums+=node.count;break;
            }else {
                node=node.left;
            }
        }
        return nums;
    }
}

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank obj = new StreamRank();
 * obj.track(x);
 * int param_2 = obj.getRankOfNumber(x);
 */
```