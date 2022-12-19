### 解题思路
申请两个栈，一个用来存储数据，一个用来存储当前的最小值
例如 0 1 0 -2
push 0 ===> stack:0 minstack：0
push 1 ===> stack:0 1 minstack：0
push 0 ===> stack:0 1 0 minstack：0 0
push -2 ===> stack:0 1 0 -2 minstack：0 0 -2
min: ===> minstack.getLast() -2
pop ===> stack:0 1 0 minstack：0 0
min: ===> minstack.getLast() 0
pop ===> stack:0 1 minstack：0
min: ===> minstack.getLast() 0
pop ===> stack:0 minstack：0
。。。
### 代码

```java
class MinStack {

    /** initialize your data structure here. */
    Deque<Integer> stack;//存储数据
    Deque<Integer> minstack;//存储当前最小值
    public MinStack() {
        stack = new LinkedList<Integer>();
        minstack = new LinkedList<Integer>();
    }
    
    public void push(int x) {   
        stack.offerLast(x);
        if(minstack.size() > 0){
            if(minstack.getLast() >= x){//注意这里是小于等于！！！
                //因为假设连续push 0 1 0
                //不把第二个零加入minstack,第一次pop的时候，minstack就为空了，就不能存储1 0的最小值了
                minstack.offerLast(x);
            }
        }else{
            minstack.offerLast(x);
        }
    }
    
    public void pop() {
        if(stack.size() == 0){
            return;
        }
        int ele = stack.getLast();
        stack.pollLast();
        //System.out.println(ele);
        //System.out.println(minstack.getLast());
        if(minstack.getLast() == ele){
            minstack.pollLast();
        }
    }
    
    public int top() {
        if(stack.size() > 0){
            return stack.getLast();
        }
        return -1;
    }
    
    public int min() {
        if(minstack.size() > 0){
            return minstack.getLast();
        }
        return -1;
    }
}
```