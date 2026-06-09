### 解题思路
定义一个栈,
遍历pushed放到栈中,并且定义一个指针j,用于指向poped数组的位置
判断栈顶元素是否等于poped[j],如果相等,就弹出对应的元素指针下移,继续进行判断
最终栈为空则满足返回true
### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int length=pushed.length;
        Stack<Integer> statck=new Stack();
        int j=0;
        for(int i=0;i<pushed.length;i++){
            statck.push(pushed[i]);
            while(!statck.isEmpty()&&j<length&&statck.peek()==popped[j]){
                statck.pop();
                j++;
            }
        }
        return statck.isEmpty();
    }
}
```