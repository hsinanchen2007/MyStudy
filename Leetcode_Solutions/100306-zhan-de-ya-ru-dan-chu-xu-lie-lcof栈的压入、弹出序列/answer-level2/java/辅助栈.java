### 解题思路
参考官方思路：
1.设置一个辅助栈
2.题目的意思其实是：如果通过入栈和出栈操作第一个序列，是否可以实现第二个序列的结果。
3.出栈就是将栈顶的数据移除，所以，我们遍历第一个入栈序列，不断将数据入辅助栈的同时，和出栈序列的元素进行比较，相同则完成一个出栈，继续重复该操作
4.直到全部入栈，之后判断出栈的索引值时候和入栈序列长度是否相同，相同发挥true；
### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
       int length=pushed.length;
        int index=0;
         Stack<Integer> stack = new Stack<>();
          for(int i=0;i<length;i++){
              stack.add(pushed[i]);

             while(index<=i&&stack.peek()==popped[index]){
                 index++;
                 stack.pop();
             }
          }
 
     return index== length;
    }
}
```