这道题，最简单直观的解法，是利用链表或者栈将所有元素都递归解析开来，然后线性读取的方式。但是这种方式在我的数据量很大，但是我只想读取一两个数据时，会存在很大的时间消耗。

下面介绍一种利用一个指针去定位当前元素的方式，有点像链表里的迭代器。这样可以省去将数据进行push和pop的操作。

**核心：**
1、用一个指针记录下一步应该读取的位置。
2、用栈来保存递归调用的List（因为要保存外层的List，还要保存外层List下一次遍历的位置，所以我用了两个栈）。

```java
public class NestedIterator implements Iterator<Integer> {
    Stack<List<NestedInteger>> stack = new Stack<>();
    Stack<Integer> ptrStack = new Stack<>();
    List<NestedInteger> curList;
    int ptr = 0;

    public NestedIterator(List<NestedInteger> nestedList) {
        curList = nestedList;
    }

    @Override
    public Integer next() {
        // hasNext()后，指针一定是指在下一个Integer上的，所以直接取就好了
        if (hasNext()) {
            return curList.get(ptr++).getInteger();
        } else {
            return null;
        }
    }

    @Override
    public boolean hasNext() {
        // 当List遍历到结尾时，要跳出递归
        while (ptr == curList.size() && !stack.isEmpty()) {
            ptr = ptrStack.pop();
            curList = stack.pop();
        }
        // 最后一个List遍历完了，就结束了
        if (ptr == curList.size()) {
            return false;
        }
        
        // 判断是Integer还是List
        if (curList.get(ptr).isInteger()) {
            return true;
        } else {
            ptrStack.push(ptr + 1);
            stack.push(curList);
            curList = curList.get(ptr).getList();
            ptr = 0;
            return hasNext();
        }
    }
}
```
