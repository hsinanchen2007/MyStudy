### 解题思路
|(&(t,f,t),!(t))
每一个表达式都能被解析成这样 | & t f t ! t
倒着计算 
入栈t 遇到运算符 出栈t 入栈 !t
类型 逆波兰表达式求值这个 但是每次碰到运算符需要记录出栈数量
出栈数量是根据括号来的;
详细的注解 ..

### 代码

```java
class Solution {
    public boolean parseBoolExpr(String expression) {
        LinkedList<Boolean> res = new LinkedList<>();
        parseBool(res, expression, expression.length()-1);
        return res.getFirst();
    }

    //返回的是下标 入栈出栈在方法内部
    //碰到中间有括号的 需要直接调到对应的下标 不在是减1了
    public int parseBool(LinkedList<Boolean> res, String expression, int index) {
        char f;
        int removeSize = 0; //控制出栈次数 入栈一次出栈一次
        while ((f = expression.charAt(index)) != '|' && f != '!' && f != '&') {
            switch (f) {
                case ',': break;
                case '(': break;
                case 't': {
                    res.addLast(Boolean.TRUE);
                    removeSize ++;
                    break;
                }
                case 'f': {
                    res.addLast(Boolean.FALSE);
                    removeSize ++;
                    break;
                }
                case ')': {
                    index = parseBool(res, expression, index-1) - 1;
                    if (index < 0) { return -1; } //已经解析完 
                    removeSize ++; //未解析玩的情况就是中间有括号 也算入栈一次 出栈次数+1
                    break;
                }
            }
            index = index - 1;
        }
        switch (f) {
            case '|': {
                Boolean t = Boolean.FALSE;
                while (removeSize >= 1) {
                    t = res.removeLast()||t; //短路运算符, 注意要先移除
                    removeSize--;
                }
                res.addLast(t);
                return index;
            }
            case '&': {
                Boolean t = Boolean.TRUE;
                while (removeSize >= 1) {
                    t = res.removeLast()&&t; //短路运算符, 注意要先移除
                    removeSize--;
                }
                res.addLast(t);
                return index;
            }
            default: {
                Boolean t = res.removeLast();
                res.addLast(!t);
                return index;
            }
        }
    }
}
```