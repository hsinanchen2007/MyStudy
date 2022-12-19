### 解题思路
通过双指针p1, p2各自指向数组pushed与popped；
循环执行下列操作，直到p1超过pushed.length（此处一定是超过，而不是小于）
    如果popped[p2] == 栈顶，则p2++;
    否则，push[p1++]入栈；
结束循环之后，判断p2与popped.length的关系，即可知道结论是true还是false；
### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        if(pushed.length == 0)  return true;
        Stack<Integer> stack =  new Stack<>();
        //stack.push(pushed[0]);
        int p1 = 0;
        int p2 = 0;
        while(p1 <= pushed.length){
            if(stack.size() != 0 && stack.peek() == popped[p2]){
                p2++;
                stack.pop();
            }
            else{
                if(p1 == pushed.length) 
                    p1++;
                else
                    stack.push(pushed[p1++]);
            }
        }

        if(p2 == popped.length) return true;
        else return false;

    }
}
```