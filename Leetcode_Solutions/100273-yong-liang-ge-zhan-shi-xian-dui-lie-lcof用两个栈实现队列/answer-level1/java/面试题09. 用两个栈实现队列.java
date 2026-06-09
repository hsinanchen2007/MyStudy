### 解题思路
题干要求使用两个栈实现队列。栈的特点是“先进后出“，队列的特点是”先进先出”。
可以使用一个栈A来存储元素，为了达到“先进先出，后进后出“，每一次都要将元素存放在栈的底部，这样消费数据时顺序才是正确的。
由此借助另一个栈B，按一下步骤存放元素：
1、将栈A已经存在的元素转移到辅助栈B中
2、向栈A中插入当前元素
3、将步骤1中转移的元素按照原来的顺序压入栈A

**在java中，栈stack底层使用数组实现，插入元素时可能会引起扩容操作，实际上效率是不高的。**

### 代码

```java
class CQueue {
    // 栈elementData用来存储元素
    private Stack<Integer> elementData=new Stack<Integer>();
    // 栈tempStack用来辅助移动elementData中的元素
    private Stack<Integer> tempStack=new Stack<Integer>();
    public CQueue() {
    }
    
    public void appendTail(int value) {
        // 将elementData中的元素先转移到辅助栈中
        transfer(elementData,tempStack);
        // 将当前元素插入到栈的最底部，它将最后被取出
        elementData.push(value);
        // 将先前的元素转移回到elementData中
        transfer(tempStack,elementData);
    }
    
    public int deleteHead() {
        // 由于元素已经调整为先存储的数据位于栈的顶部，直接弹出顶部数据即可
        if(elementData.empty()){
            return -1;
        }else{
            return elementData.pop();
        }
    }

    private void transfer(Stack<Integer> src,Stack<Integer> dest){
        while(!src.empty()){
            dest.push(src.pop());
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