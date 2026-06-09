1. 方法1 **迭代**： 用队列，把每一层的值存起来，然后两点连起来

```
	    public Node connect(Node root) {
	    	
	    	 if(root==null)return root;	        
		     Queue< Node> waitQueue=new LinkedList<Node>();
		     waitQueue.add(root);
		     while(!waitQueue.isEmpty()) {
		    	 int size=waitQueue.size();
		    	 //System.out.println("size"+size);
		    	 Node temp=null;
		    	 for(int i=0;i<size;i++) {
		    		  temp =waitQueue.poll();
		    		 temp.next=waitQueue.peek();
		    		 if(temp.left!=null) {
		    			 waitQueue.add(temp.left);
		    		 }
		    		 if(temp.right!=null) {
		    			 waitQueue.add(temp.right);
		    		 }
		    	 }
		    	 temp.next=null;  // 这句话是必须的，因为上述size虽然能够分层次，但是因为元素已经添加上了队列，使得
		    	              // 该层的最后一个元素后面会跟着子层的元素。
		     }
		     return root;
	    }
```

方法2： 递归
![微信图片_20200103164703.png](https://pic.leetcode-cn.com/65542efd24b0a01f56f660d583381585fa0b28a48a7aff9ecae263d787c96c64-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200103164703.png)

```
	    // 方法2 递归
	    public Node connect(Node root) {
	    	if(root==null) return root; 
	    	 nextconnect(root);
		     return root;
	    }
	    public void nextconnect(Node root) {
	    	Node pre=null; // 用来记录两指向节点的左节点
	    	Node temproot=null;  // 用来记录第一个节点，作为递归的输入
	    	if(root!=null) {
	    		while(root!=null) {
	    			if(root.left!=null) { // 左子
	    				if(pre!=null) {
	    					pre.next=root.left;
	    					
	    				}
	    				pre=root.left;
	    				if(temproot==null) {
	    					temproot=root.left;
	    				}
	    			}
	    			if(root.right!=null) {// 右子
	    				if(pre!=null) {
	    					pre.next=root.right;
	    					
	    				}
	    				pre=root.right;
	    				if(temproot==null) {
	    					temproot=root.right;
	    				}
	    			}
	    			root=root.next;
	    		}
	    		nextconnect(temproot);
	    	}else {
	    		return;
	    	}
	    }
```
