```
class Solution{
	Node connect(Node root) {
	    if(root!=null){
            
	    	if(root.left!=null)root.left.next=root.right;
            
	        Node first = root.left!=null?root.left:root.right;
	        while(first!=null){//每一层开始的第一个节点
	            Node p = first;
                //寻找第一个非叶节点
	            while(p!=null&&p.left==null&&p.right==null)p = p.next;
                
	            if(p==null)break;//全是叶子节点则跳出循环
                
	            first = p.left!=null?p.left:p.right;//下一层开始的节点
                
				Node pre = null;
	            while(p!=null){//连接下一层的所有节点
	            	if(p.left!=null&&p.right!=null){
	            		if(pre!=null)pre.next = p.left;
	            		p.left.next = p.right;
	            		pre = p.right;
	            	}else if(p.left!=null||p.right!=null){
	            		Node t = p.left!=null?p.left:p.right;
	            		if(pre!=null)pre.next = t;
	            		pre = t;
	            	}
	            	p = p.next;
	            }
	        }
	    }
	    return root;
	}
}
```
