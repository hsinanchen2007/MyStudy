### 解题思路

解法1

复杂度
```
    时间：O（1），每个元素值进栈和出栈各一次
    空间：O（n）
```
优缺点
```
    缺点：由于相减和相加可能会导致int类型溢出，所以这里用c++里面64位的long long类型
    优点：只用了一个栈和额外long lon个变量，比解法二更省空间
```
```cpp
class MinStack {
    typedef long long ll;
public:
    ll topElem; 
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if(s.empty()) {
            minn = x;
            s.push(x-minn);  //(当前值x-最小值minn)进栈
        }
        else {
            s.push(x-minn);
            minn = x < minn ? x : minn;  //值得注意的是当栈顶元素<0,则说明栈顶元素就是minn
        }
    }
    
    void pop() {
        if(!s.empty()) {
            topElem = s.top();
            s.pop();
            //原来的值x-最小值minn = topElem
            //topElem<0,说明原来值x更小(原来的值就是现在的minn)，则现在的minn应该被更新minn-topElem
            if(topElem < 0) minn -= topElem;
        }
        return;
    }
    
    int top() {
        if(!s.empty()) {
            topElem = s.top();
        }
        if(topElem < 0) return minn; //说明topElem <0, 说明 x<minn, minn已经被更新为当栈顶x，栈顶元素就是minn
        return topElem+minn;
    }
    
    int getMin() {
        return minn;
    }
    private:
        ll minn;
        stack<ll>s;
};
```

解法2

复杂度
```
    时间：0(1)，每个元素值进栈和出栈各一次
    空间：0(n)
```
优缺点
```
    缺点：代码理解起来更简单
    优点：和minn相比，当前元素x更小的话，要先把之前的minn进栈，再minn=x，之前的min进栈会更消耗空间
```
```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x)
        if(x <= minn) {  //当前元素x小于等于最小值minn时，要先把minn进栈，再更新，即minn=x
            s.push(minn);
            minn = x;
        }
        s.push(x);
    }
    
    void pop() {
        if(!s.empty()) {
            if(s.top() == minn)  {  //最小元素minn要更新成次栈顶元素
                s.pop();
                minn = s.top();
            }
        }
         s.pop();//把多余栈顶元素出栈，也是就当前的minn
    }
    
    int top() {
        if(!s.empty()) return s.top();
        return NULL;
    }
    
    int getMin() {
        return minn;
    }
    private:
        stack<int>s;
        int minn = INT_MAX; //初始化成int类型的最大值
};
```

解法3

复杂度
```
    时间：0(1)，因为采用头插法push元素进链表
    空间：0(n)
```

```java
class MinStack {
    class Node{
        int value;
        int min;
        Node next;

        Node(int x, int min){
            this.value=x;
            this.min=min;
            next = null;
        }
    }
    Node head;
    //每次加入的节点放到头部
    public void push(int x) {
        if(null==head){
            head = new Node(x,x);
        }else{
            //头插法，当前值和之前头结点的最小值较小的做为当前的 min
            Node n = new Node(x, Math.min(x,head.min));
            n.next=head;
            head=n;
        }
    }

    public void pop() {
        if(head!=null)
            head =head.next;
    }

    public int top() {
        if(head!=null)
            return head.value;
        return -1;
    }

    public int getMin() {
        if(null!=head)
            return head.min;
        return -1;
    }
}
```

