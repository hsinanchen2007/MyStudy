![1574400260(1).jpg](https://pic.leetcode-cn.com/fe13bb207e3c97b71a88c75341995d00d4f5bc092a2b1f8d76ad2ce8f7a55d13-1574400260\(1\).jpg)

代码如下
```
 public static boolean isValid(String s){
        // 判断符号的长度是否为奇数，奇数直接返回false
        if((s.length() & 1) == 1){
            return false;
        }

        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            if(stack.isEmpty()){
                stack.push(s.charAt(i));
            } else {
                // 只需处理右括号，其余情况压入栈即可
                switch (s.charAt(i)){
                    case ')': {
                        if(stack.pop() != '('){
                            return false;
                        }
                        break;
                    }
                    case ']': {
                        if(stack.pop() != '['){
                            return false;
                        }
                        break;
                    }
                    case '}': {
                        if(stack.pop() != '{'){
                            return false;
                        }
                        break;
                    }
                    default: stack.push(s.charAt(i));
                }
            }
        }
        // 如果栈不为空，说明括号有重复单边括号，返回false
        if(!stack.isEmpty())
            return false;
        return true;
    }
```
