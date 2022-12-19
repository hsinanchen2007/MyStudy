### 1. 题目分析
- 移除无效的括号$\rightarrow$通过栈实现
- 我们可以使用**一个栈存储括号，一个`StringBuilder`进行字符串重组**，其具体思路为：
    - 扫描字符串，分类讨论： 
        - 如果字符为小写字母，直接加入`StringBuilder`
        - 如果字符为左括号，入栈，加入`StringBuilder`
        - 如果字符为右括号：
            - 如果栈为空，该右括号一定非法，不加入
            - 如果栈不为空，**栈顶一定为左括号**，栈顶出栈，将右括号加入`StringBuilder`
    - 扫描结束后：
        - 如果栈不为空，栈中一定全部是非法的左括号。假设此时栈大小为$k$，**从后向前删除$k$个左括号即可**
        - 如果栈为空，说明字符串本身合法
    - 将`StringBuilder`转换为字符串，返回
### 2. Coding
```java
public String minRemoveToMakeValid(String s) {
    Stack<Character> stack = new Stack<>();
    StringBuilder sb = new StringBuilder();
    for(int i = 0; i < s.length(); i ++){
        char c = s.charAt(i);
        if(c >= 97){
            sb.append(c);
        }
        else if(c == 41){
            if(stack.isEmpty()){
                continue;
            }
            else {
                stack.pop();
                sb.append(c);
            }
        }
        else {
            stack.push(c);
            sb.append(c);
        }
    }
    for(int i = 0; i < stack.size(); i ++){
        sb.deleteCharAt(sb.lastIndexOf("("));
    }
    return sb.toString();
}
```
时间复杂度：$O(n)$，空间复杂度：$O(n)$
### 3. 执行结果
![image.png](https://pic.leetcode-cn.com/ab0fa508a08d2d70c2e172b32aa1a8911820d9b97e16366b95621df30c7b9d52-image.png)
