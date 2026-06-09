```
public String reverseStr(String s, int k) {
        if (k == 1 || s.equals(""))
            return s;
        Stack<Character> stackRE = new Stack<>();//需要反转输出的栈
        List<Character> list = new ArrayList<>();//需要顺序输出的队列
        char[] c = s.toCharArray();
        int start = 0;
        StringBuilder sb = new StringBuilder();
        while (start < c.length) {
            if (start % (2 * k) < k) {
                while (!list.isEmpty()) {
                    sb.append(list.remove(0));
                }
                stackRE.push(c[start]);
            } else {
                while (!stackRE.isEmpty()) {
                    sb.append(stackRE.pop());
                }
                list.add(c[start]);
            }
            start++;
        }
        //当循环结束时，判断队列和栈中是否还有元素
        while (!stackRE.isEmpty()) {
            sb.append(stackRE.pop());
        }
        while (!list.isEmpty()) {
            sb.append(list.remove(0));
        }
        return sb.toString();
    }
```

