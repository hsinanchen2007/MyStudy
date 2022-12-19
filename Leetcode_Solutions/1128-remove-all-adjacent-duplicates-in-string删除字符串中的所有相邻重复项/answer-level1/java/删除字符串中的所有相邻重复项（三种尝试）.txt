这个方法是别人的解法。比自己之前的解法更好。

把每个字符入栈前, 判断是否和栈顶元素相同, 如果相同则不入栈, 栈顶元素出栈. 由于删除字符后的字符串长度一定是小于原字符串. 所以可以直接用原字符数组作为栈.

#### 直接使用原数组作为栈

```Java
class Solution {
    public String removeDuplicates(String S) {
        char[] stack = S.toCharArray();
        int top = -1;
        for (char c : stack) {
            if (top > -1 && stack[top] == c) {
                top--;
                continue;
            }
            stack[++top] = c;
        }
        return new String(stack, 0, top + 1);
    }
}
```

#### 单栈实现非最优解（超出时间限制）
```Java
class Solution {
    public String removeDuplicates(String S) {
        Stack<String> s = new Stack<>();
        String[] s_arr = S.split("");
        for(int i=s_arr.length-1;i>=0;i--){
            if(s.empty()){
                s.push(s_arr[i]);
            }else{
                if(s.peek().equals(s_arr[i])){
                    s.pop();
                    s_arr[i] = "";
                }else{
                    s.push(s_arr[i]);
                }
            }
        }
        String ret = "";
        while(!s.empty()){
            ret += s.pop();
        }
        return ret;
    }
}
```




#### 双栈实现非最优解（超出时间限制）
```Java
class Solution {
    public String removeDuplicates(String S) {
        Stack<String> s1,s2;
        s1 = new Stack<String>();
        s2 = new Stack<String>();
        String[] s_arr = S.split("");   
        for(int i=0;i<s_arr.length;i++){
            s1.push(s_arr[i]);
        }
        while(!s1.empty()){
            if(s2.empty()){
                s2.push(s1.pop());
            }else{
                if(!s2.peek().equals(s1.peek())) s2.push(s1.pop());
                else{
                    s1.pop();
                    s2.pop();
                }
            }
        }
        String ret = "";
        while(!s2.empty()){
            ret += s2.pop();
        }
        return ret;
    }
}
```