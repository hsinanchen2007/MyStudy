    public String decodeString(String s) {
        if (s.isEmpty())
            return s;
        StringBuffer str = new StringBuffer(s);
        StringBuffer res = new StringBuffer();
        LinkedList<String> stack = new LinkedList<>();
        for (int i = 0; i < str.length(); i++) {
            int index = i;
            while (index < str.length() && (str.charAt(index) != '[' && str.charAt(index) != ']'))
                index++;
            if (index != i) {
                stack.push(str.substring(i, index));
                i = index - 1;
            } else {
                if (str.charAt(i) == '[')
                    stack.push("[");
                else {
                    StringBuffer ss = new StringBuffer();
                    while (!stack.peekFirst().equals("[")) {
                        ss.insert(0, stack.pop());
                    }
                    stack.pop();
                    String number = stack.pop();
                    int j = 0;
                    for (j = number.length() - 1; j >= 0; j--) {
                        if (number.charAt(j) < '0' || number.charAt(j) > '9') {
                            break;
                        }
                    }
                    StringBuffer tmp = new StringBuffer();
                    int num = Integer.valueOf(number.substring(j + 1));
                    while (num != 0) {
                        tmp.append(ss);
                        num--;
                    }
                    tmp.insert(0, number.substring(0, j + 1));
                    if (!ss.toString().isEmpty())
                        stack.push(tmp.toString());
                }
            }

        }
        while (!stack.isEmpty()) {
            res.insert(0, stack.pop());
        }
        return res.toString();
    }