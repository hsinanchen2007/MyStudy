 ![image.png](https://pic.leetcode-cn.com/a8e21bd7510b0b42aba4e7232df96fa47853dc64b61bc1318b0a19886c639fef-image.png)
看到这个题第一个想法就是 `LinkedList` ，但是明显题目中要求的东西比JDK要求的简单很多，只是左侧弹出和右侧添加而已，另外就是还有一个获取最大值的方法。  
既然这样，我们就完全没必要在这种刷算法题的时候使用系统的List和Queue来实现了，那就自己写一个极简的链表；   
链表肯定要有节点对象，我们的节点对象只需要保存值，和下一个节点就OK了，所以我们定义一个内部类
```
    class Node {
        int value;
        Node next;
    }
```
我们在要实现的MaxQueue定义内部类后，还有定义属性首节点 first，尾节点 last，以及最大值节点maxNode
 我们只需要每次添加将原last节点的next，指向添加数据的节点；并将新节点设置为最后的节点，同时与最大值节点比较；
弹出时，只需要将first节点值获取，并将first 指向下一个节点;
这个样子可以说除了首节点为最大值节点需要重新查找最大值的情况外，三个方法的复杂度是真正的O(1)
```
class MaxQueue {
        //队列的首节点
        transient Node first;
        // 队列最后节点
        transient Node last;
        //队列最大值的节点
        transient Node maxNode;

        public MaxQueue() {
        }
        public int max_value() {
            if (maxNode == null){
                return -1;
            }
            return maxNode.value;
        }

        public void push_back(int value) {
            Node newNode = new Node();
            newNode.value = value;
            if(last == null){ // 如果没有最后节点则是空队列
                maxNode = first = last = newNode;
            }else {
                last.next = newNode;
                last = newNode;
                if (newNode.value >= maxNode.value ){
                    maxNode = newNode;
                }
            }
        }

        public int pop_front() {
            if (first == null){
                return -1;
            }
            int result = first.value;
            if (first == maxNode){
                maxNode = null;
            }
            first = first.next;
            if (first == null){
                last = null;
            }else if (maxNode == null){
                reFoundMaxNode();//重新中查找队列中的最大节点
            }
            return result;
        }
        private void reFoundMaxNode() {
            if (first == null){
                maxNode = null;
                return;
            }
            maxNode = first;
            Node next = first;
            while (next != null){
                if (next.value >= maxNode.value){
                    maxNode = next;
                }
                next = next.next;
            }
        }

        class Node {
            int value;
            Node next;
        }
    }
```

*第一次写题解，欢迎大家指正*