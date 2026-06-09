```Java
class Solution{
	public List<List<Integer>>levelOrder(Node root){
		List<List<Integer>>res=new ArrayList<>();
		if(root==null)
			return res;
		 Queue<Node>queue=new LinkedList<>();
		 queue.offer(root);
		 while(!queue.isEmpty()){
		 	int len=queue.size();
		 	List<Integer>temp=new ArrayList<>();
		 	Node curNode=null;
		 	for(int i=0;i<len;i++){
		 		curNode=queue.poll();
		 		temp.add(curNode.val);
		 		if(curNode.children!=null){
		 			for(Node node:curNode.children){
		 				queue.offer(node);
		 			}
		 		}
		 	}
		 	res.add(temp);
		 }
		 return res;
	}
}
```