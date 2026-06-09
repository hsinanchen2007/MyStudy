思路：拿到题后首先想到，栈的实现可以通过ArrayList或者LinkedList（我使用的是链表）.而最小栈只需要用一个整数minNum记录栈中的最小值即可。
- push():每一次入栈，即为链表添加元素。与此同时，将添加的元素与minNum进行比较。
- pop():首先判断链表最后一个元素是否与minNum值相等。若相等，则从头遍历链表，找出第二小的元素。最后删除链表最后一个元素。
```
class MinStack {
    List<Integer> list=new LinkedList<Integer>();
    int minNum=Integer.MAX_VALUE;
    /** initialize your data structure here. */
    public MinStack() {
        
    }  
    public void push(int x) {
        list.add(x);
        if(x<minNum){
            minNum=x;
        }
    }   
    public void pop() {
        if(minNum==list.get(list.size()-1)){
            minNum=Integer.MAX_VALUE;
            for(int i=0;i<list.size()-1;i++){
                if(list.get(i)<minNum){
                    minNum=list.get(i);
                }
            }
        }
        if(list.size()!=0){
            list.remove(list.size()-1);
        } 
    }
    
    public int top() {  
        return list.get(list.size()-1);
    }
    
    public int getMin() {
        return minNum;
    }
}

```
**结果：战胜 93.07 % 的 java 提交记录**