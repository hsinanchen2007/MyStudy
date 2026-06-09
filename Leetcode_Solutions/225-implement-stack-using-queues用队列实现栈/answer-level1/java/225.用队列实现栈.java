```
class MyStack{
	Queue<Integer>queue1;
	Queue<Integer>queue2;
	public MyStack(){
		queue1=new LinkedList<>();
		queue2=new LinkedList<>();
	}
	public void push(int x){
		queue1.offer(x);	
	}
	public int pop(){
		while(!queue1.isEmpty()){
			int temp=queue1.poll();
			if(queue1.isEmpty()){
				while(!queue2.isEmpty()){
					queue1.offer(queue2.poll());
				}
				return temp;
			}else{
				queue2.offer(temp);
			}
		}
	}
	public int top(){
		while(!queue1.isEmpty()){
			int temp=queue1.poll();
			if(queue1.isEmpty()){
				queue2.offer(temp);
				while(!queue2.isEmpty()){
					queue1.offer(queue2.poll());
				}
				return temp;
			}else{
				queue2.offer(temp);
			}
		}
	}
	public boolean empty(){
		return queue1.isEmpty();
	}
}
```