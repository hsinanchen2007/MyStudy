### 解题思路
详见代码注释

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
        //自己造轮子,采用的方式为链表栈
        class Node {
            //保存当前值
            int value;
            //保存每次判断的最小值
            int min;
            //next指针
            Node next;
            //初始化方法
            Node (int x,int min){
                this.value = x;
                this.min = min;
                next = null;
            }
        }
    //初始化
    Node head;
    //压栈操作
    public void push(int x) {

        if(null == head){
            head = new Node(x,x);
        }else {
            //如果栈内有数据，就进行比较 然后将比较的值 加入到头节点的min值中
            Node n = new Node (x,Math.min(x,head.min));
            n.next = head;
            head = n;
        }
    }
    //出栈
    public void pop() {
        if(head != null){
            head= head.next;
        }
    }
    //获取栈顶数据
    public int top() {
        if(head != null){
            return head.value;
        }
        return -1;
    }
    //获取最小值，即为栈顶的min值
    public int getMin() {
        if(head != null){
            return head.min;
        }
        return -1;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```