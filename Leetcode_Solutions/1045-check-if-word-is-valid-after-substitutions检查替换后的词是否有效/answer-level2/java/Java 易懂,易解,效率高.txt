**1.考察栈,所以用栈来解此题;
2.针对字母c,当前字母为c时,就pop b and pop a,如果能正常执行,则无误,反之则有错;
3.最后判断栈是否为空即可;
4.完结。**


        public boolean isValid(String S) {
            Stack<Character> stack = new Stack<>();
            for (int i = 0; i < S.length(); i++) {
                if (S.charAt(i) == 'c') {
                    if (stack.empty() || stack.pop() != 'b')
                        return false;
                    if (stack.empty() || stack.pop() != 'a')
                        return false;
                } else {
                    stack.push(S.charAt(i));
                }
            }
            return stack.isEmpty();
        }

**以下方法适合刚入门的小伙伴**

        public boolean isValid(String S) {
            while (S.contains("abc"))
                S = S.replace("abc", "");
            return S.equals("");
        }