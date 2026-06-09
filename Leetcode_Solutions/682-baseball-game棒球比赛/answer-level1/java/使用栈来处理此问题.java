### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    public int calPoints(String[] ops) {
        Stack stack = new Stack();
    
        for(int i = 0;i<ops.length;i++){
            String s = ops[i];
            if("C".equals(s)){
                // 删除栈顶元素
                stack.pop();
            }else if("D".equals(s)){
                // 弹出栈顶元素乘以 2 ，再压入栈顶
                int num = stack.peek();
                stack.push(num*2);

            }else if("+".equals(s)){
                // 获取 栈顶的两个元素之和再压入栈顶
                int num1 = stack.pop();
                int num2 = stack.peek();
                stack.push(num1);
                stack.push(num1 + num2);
            }else{
                int num = Integer.parseInt(s);
                stack.push(num);
            }
        }

        int sum = 0;
        while(stack.count>0){
            sum+=stack.pop();
        }
        return sum;
    }

    static class Stack{
        // 哨兵节点
        Node top = new Node(0,null);
        int count;

        public void push(int x){
            top.next = new Node(x, top.next);
            count++;
        }

        public int pop(){
            if(count == 0){
                return 0;
            }
            int x = top.next.value;
            top.next = top.next.next;
            count--;
            return x;
        }

        public int peek(){
            if(count==0){
                return 0;
            }
            return top.next.value;
        }

    }

    static class Node{
        int value;
        Node next;
        public Node(int value, Node next){
            this.value = value;
            this.next= next;
        }
    }


}
```