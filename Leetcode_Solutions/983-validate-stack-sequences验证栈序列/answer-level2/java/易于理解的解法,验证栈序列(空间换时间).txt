### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        /**
         此题可以使用基本的数组代表一个简单的栈,
         首先分配三个变量,in指针代表pushed第i个进栈的指向
         out指针代表popped出栈的指向
         top指针代表遍历过程pushed中并没有出栈的元素
         pushed代表着元素进栈的顺序
         popped代表着元素出栈的顺序
         由于进栈和出栈的顺序不一致,
         遍历pushed元素和popped元素是否一致,pushed出栈
         stack临时存储最后出栈次序的元素
        **/
        int in=0,out=0,top=0;
        int[] stack = new int[pushed.length];
        while (in<pushed.length){
            //如果栈顶有元素并且元素的值刚好等于popped[out],出栈
            if(top>0&&stack[top-1]==popped[out]){
                top--;
                out++;
                continue;
            }
            //如果stack没有元素或者栈顶元素不等于popped[out]的值时
            if(pushed[in]==popped[out]){
                out++;
                in++;
            }else {
                //如果此时in指向的元素不等于popped[out](即in指向的元素并不出栈),先放到临时栈中
                stack[top++] = pushed[in++];
            }
        }
        if(top==0) return true;//如果临时栈并没有元素时,说明出栈验证完毕.
        while (out<popped.length){
            if(stack[top-1]!=popped[out]){//剩余的stack栈中的次序与popped不一致,说明次序不正确
                return false;
            }
            top--;
            out++;
        }
        return true;
    }
}
```

