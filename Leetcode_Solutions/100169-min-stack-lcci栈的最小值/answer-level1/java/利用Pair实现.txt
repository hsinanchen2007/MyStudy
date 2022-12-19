```
class MinStack {
    class Pair{
        private int key;
        private int value;
        
        public Pair(int k,int v){
            key=k;
            value=v;
        }
        
        public int getKey(){
            return key;
        }
        
        public int getValue(){
            return value;
        }
    }
    
    Stack<Pair> s;

    /** initialize your data structure here. */
    public MinStack() {
        s=new Stack<>();
    }
    
    public void push(int x) {
        if(s.isEmpty()){
            s.push(new Pair(x,x));
        }else{
            s.push(new Pair(x,Math.min(x,getMin())));
        }
    }
    
    public void pop() {
        if(!s.isEmpty()){
            s.pop();
        }
    }
    
    public int top() {
        return s.peek().getKey();
    }
    
    public int getMin() {
        return s.peek().getValue();
    }
}
```
