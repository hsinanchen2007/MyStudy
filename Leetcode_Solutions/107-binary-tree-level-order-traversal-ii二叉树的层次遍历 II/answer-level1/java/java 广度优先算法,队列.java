首先先求出正向排列的列表list
```
  List<List<Integer>>result = new ArrayList<>();  
       
        Queue<TreeNode>queue = new LinkedList<TreeNode>();
        queue.add(root);
        int level = 0;
        
        if(root==null){
            return result;
        }
        
        while(!queue.isEmpty()){
            
            List<Integer>list = new ArrayList<>(); 
            
           //注意这里有坑，一定要先拿到队列里元素的个数，而不能把queue.size()写在循环体里，因为在for循环里queue.size()是不断变化的.
            int length = queue.size();
            
            for(int i=0;i<length;i++){
                
                TreeNode node = queue.remove();
                list.add(node.val);
                
                if(node.left!=null){
                   queue.add(node.left); 
                }
                if(node.right!=null){
                    queue.add(node.right); 
                }
                
            }
            
            result.add(list);
            level++;
            
        }


```

最后再反转列表list
```
Collection.reverse();
```


