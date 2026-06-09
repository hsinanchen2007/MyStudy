### 解题思路
定义好操作符的优先级；
用2个栈分别存放number与op；
在轮到自己优先级的时候，触发计算。

除了error cases外，需要留意一些 corner cases。
### 代码

```java
class Solution {
    private final char START = '^';
    private final char END = '$';
    private final HashMap<Character, Integer> opProirity = new HashMap<Character, Integer>() {
        {
            put('*', 4);
            put('/', 4);
            put('+', 2);
            put('-', 2);
            put(')', 1);
            put('(', 1);
            put(END, 0);
            put(START, 0);
        }
    };

    public int calculate(String s) {
        if(s==null || "".equals(s)){
            return 0;//todo it is good to throw EXCEPTION
        }

        LinkedList<Integer> numberStack = new LinkedList<Integer>();
        LinkedList<Character> opStack = new LinkedList<Character>();
        opStack.add(START);

        int strLen = s.length();
        StringBuilder intSb = new StringBuilder();
        for (int i = 0; i <= strLen; i++) {
            char c = (i == strLen) ? END : s.charAt(i);
            int opL, opR;
            int ret;
            switch (c) {
                case ' ':
                    tryStoreIntNumber(intSb, numberStack);
                    break;
                case '(':
                    tryStoreIntNumber(intSb, numberStack);
                    opStack.addLast(c);
                    break;
                case ')':
                    tryStoreIntNumber(intSb, numberStack);
                    do {
                        if (opStack.peekLast() != '(') {
                            calcLast2Numbers(numberStack, opStack);
                        }
                    } while (opStack.peekLast() != '(');
                    /// pop '('
                    opStack.pollLast();
                    /// don't push ')'
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    tryStoreIntNumber(intSb, numberStack);
                    while (opStack.peekLast() != START && isNotHigerPriority(c, opStack.peekLast())) {
                        calcLast2Numbers(numberStack, opStack);
                    }
                    opStack.addLast(c);
                    break;
                case '$': /// end of eval
                    tryStoreIntNumber(intSb, numberStack);
                    while (opStack.size() > 1) {
                        calcLast2Numbers(numberStack, opStack);
                    }
                    break;
                default: /// digit
                    intSb.append(c);
                    break;
            }
        }

        return numberStack.getFirst();
    }

    private void tryStoreIntNumber(StringBuilder intSb, LinkedList<Integer> numberStack) {
        if (intSb.length() > 0) {
            int v = Integer.parseInt(intSb.toString());
            numberStack.addLast(v);
            intSb.delete(0, intSb.length());
        }
    }

    private boolean isNotHigerPriority(char preOp, char curOp) {
        return opProirity.get(preOp) <= opProirity.get(curOp);
    }

    private void calcLast2Numbers(LinkedList<Integer> numberStack, LinkedList<Character> opStack) {
        int opR = numberStack.pollLast();
        int opL = numberStack.pollLast();
        char op = opStack.pollLast();

        int ret = doOp(opL, opR, op);
        numberStack.addLast(ret);
    }

    int doOp(int l, int r, char op) {
        switch (op) {
            case '+':
                return l + r;
            case '-':
                return l - r;
            case '*':
                return l * r;
            case '/':
                if (r == 0) {
                    throw new ArithmeticException();
                }
                return l / r;
        }
        throw new IllegalArgumentException();
    }
}
```