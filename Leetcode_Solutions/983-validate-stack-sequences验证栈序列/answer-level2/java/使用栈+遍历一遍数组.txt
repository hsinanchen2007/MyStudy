解法1--使用两个辅助栈
![2020032302.PNG](https://pic.leetcode-cn.com/ba94cc5f21cb2452a550a71abf844bbdcf46e8954504c97307273f5484e2380d-2020032302.PNG)
### 解题思路
使用两个栈:
声明栈stackPush, 将数组pushed中的数放入栈stackPush中

声明栈stackPop, 将数组popped中的数放入栈stackPop中

先遍历一遍数组popped, 将数组中的数放入栈stackPop中, (注: 因为在数组popped 中, 在索引最小的数, 最先被弹出栈, 所以, 要从数组popped的尾部开始往前遍历)

再遍历一遍数组pushed, 先将pushed[i] 入栈stackPush中, 再判断stackPush中的栈顶元素和stackPop栈顶中的元素是否相等

在栈stackPush非空的情况下, 若栈stackPush和栈stackPop的栈顶元素相等, 则将stackPush和stackPop不断进行出栈操作

最后判断stackPush 是否为空(即stackPush中是否还存在未被弹出的元素),

若stackPush为空, 返回true;

若stackPush不为空, 返回false;
### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Deque<Integer> stackPop = new LinkedList<>();
        Deque<Integer> stackPush = new LinkedList<>();
        for(int i=popped.length-1;i>=0;i--){
            stackPop.push(popped[i]);
        }
        for(int i=0;i<pushed.length;i++){
            stackPush.push(pushed[i]);
            while(true){
            	if(!stackPush.isEmpty()&&stackPop.peek().equals(stackPush.peek())) {
                    stackPush.pop();
                    stackPop.pop();
            	}else {
            		break;
            	}
            } 
        }
        return stackPop.isEmpty();
    }
}
```
解法2--仅使用一个栈来存放数组pushed中的元素
![2020032301.PNG](https://pic.leetcode-cn.com/e8fd94ab9358b673565ca6bc58b1889690a5fe9878418c5467e76c1e8d9c5783-2020032301.PNG)
思路:
首先声明栈stackPush, 存放数组pushed中的元素,

使用popped数组模拟栈, 来实现popped数组中弹出元素操作

在数组popped数组中, 左边的元素先出栈, 右边的元素后出栈, 声明变量index =0 (此时, index指向popped数组中的第一个元素);

遍历一遍数组pushed, 先将数组pushed中的元素放入栈stackPush中, 

判断stackPush栈顶元素 与index指向popped数组中当前位置的元素是否相等, 

若tsackPush非空, 并且, stackPush栈顶元素 与index指向popped数组中当前位置的元素相等, 则不断进行: 将stackPush中的元素出栈, 并且index++(使index指向下一个位置)的操作

最后判断stackPush是否为空, 若为空, 则返回true; 若非空, 则返回false;
```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Deque<Integer> stackPush = new LinkedList<>();
        int index  = 0;
        for(int i=0;i<pushed.length;i++){
            stackPush.push(pushed[i]);
            while(!stackPush.isEmpty()&&stackPush.peek()==popped[index]){
                stackPush.pop();
                index++;
            } 
        }
        return stackPush.isEmpty();
    }
}
```