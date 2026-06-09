### 解题思路
此处撰写解题思路

### 代码

```java
class CQueue {
    // 只往后添加
    LinkedList<Integer> list1;
    // 取头的时候 如果为空 则从list1的后面开始取 全部加入自己，然后顶部的就是head。
    LinkedList<Integer> list2;

    public CQueue() {
        list1 = new LinkedList<Integer>();
        list2 = new LinkedList<Integer>();
    }
    
    public void appendTail(int value) {
        list1.addLast(value);
    }
    
    public int deleteHead() {
        if(list2.size()==0){
            if(list1.size()==0){
                return -1;
            }else{
               while(list1.size()>0){
                 list2.addLast(list1.removeLast());
                }
                return list2.removeLast();
            }
        }else{
            return list2.removeLast();
        }
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```