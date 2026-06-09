### 解题思路
这个解答只是为了针对直接用LinkedList和它对应的API方法的一个质疑，按照我的代码实现，完全没必要两个LinkedList实现队列，直接利用一个LinkedList和它的removeFirst和addLast就可以实现deleteHead和appendTail方法，因此，感觉这种非使用栈的解答方法不合题目要求

### 代码

```java
class CQueue {
          LinkedList<Integer> A = new LinkedList<Integer>();
                  
    public CQueue() {

      
    }
    public void appendTail(int value) {
        A.addLast(value);
    }
    public int deleteHead() {
        if(!A.isEmpty()) return A.removeFirst();
         return -1;
    
    }

}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```