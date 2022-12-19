### 解题思路
之前在一家杭州的公司笔试题上见过，但是自己完全没准备算法题。。。。。。估计凉了

### 代码
```java
class Solution {
    /**
    *
    *这应该算栈的内容里，比较经典的关于括号匹配的问题
    *代码中间判断的部分可以抽取出来，代码冗余太大，不美观
    *优化：评论区一个大佬将括号用Map对应起来，这样代码好看，检索也方便（注释掉的是自己原始代码）
    */
    public boolean isValid(String s) {
        char[] symbol=s.toCharArray();
        Stack<Character> stack=new Stack<Character>();
        Map<Character,Character> map=new HashMap<Character,Character>(){{put('(',')');put('[',']');put('{','}');}};
        for (char c:symbol){
            if (c=='(' || c=='[' || c=='{')
                stack.push(c);  //这里自动装箱，并压入栈中
            else
                if (!stack.empty() && c==map.get(stack.peek())){
                    stack.pop();
                    continue;
                }
                else if (!stack.empty() && c!=map.get(stack.peek())) //stack栈不为空（避免找栈顶报错）且括号不匹配
                    return false;
                else    //stack栈为空，但有反括号
                    return false;
        }
        if (stack.empty())  //因为可能出现（（（（（{{{{{{[[[[这种无反括号情况
            return true;
        else
            return false;

//        for (char c:symbol){    //正向括号（例‘（’‘{’‘[’）按顺序入栈
//            if (c=='(' || c=='[' || c=='{')
//                stack.push(c);  //这里自动装箱，并压入栈中
//            else if ((c==')' || c==']' || c=='}')&& !stack.empty() ){   //出现反括号，判断是哪一种反括号，如果不匹配直接return整个程序
//                if (c==')' && stack.peek()=='(')
//                {
//                    stack.pop();
//                    continue;
//                }
//                else if (c==')' && stack.peek()=='(')
//
//                if (c==']' && stack.peek()!='[')   //如果出现的反括号]，但栈顶不是[，说明错误
//                    return false;
//                else if (c==']' && stack.peek()=='['){
//                    stack.pop();
//                    continue;
//                }
//                if (c=='}' && stack.peek()!='{')   //如果出现的反括号}，但栈顶不是{，说明错误
//                    return false;
//                else if (c=='}' && stack.peek()=='{'){
//                    stack.pop();
//                    continue;
//                }
//            }
//            else
//                return false;
//        }
//        if (stack.empty())  //因为可能出现（（（（（{{{{{{[[[[这种无反括号情况
//            return true;
//        else
//            return false;
    }
}
```