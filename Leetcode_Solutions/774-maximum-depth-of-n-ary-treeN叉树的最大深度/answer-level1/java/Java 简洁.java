```
 public int maxDepth(Node root) {
         if(root == null)
        	return 0;
        int hight = 0 ;
        for(Node node :root.children) {
        	hight = Math.max(hight, maxDepth(node));
        }
        hight++;
        return hight;
    }
```
