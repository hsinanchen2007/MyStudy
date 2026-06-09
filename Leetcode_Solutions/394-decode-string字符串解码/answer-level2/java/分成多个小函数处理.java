    public String decodeString(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        char[] cs = s.toCharArray();
        StringBuffer buffer = new StringBuffer();

        Stack<Character> stack = new Stack<>();
        for (char c : cs) {
            if (isRight(c)) {
                String minorDecodedString = getMinorEncodedString(stack);
                String decodedMinorString = decodeMinorString(minorDecodedString + ']');
                if (decodedMinorString != null) {
                    for (char e : decodedMinorString.toCharArray()) {
                        stack.push(e);
                    }
                }
                continue;
            }
            stack.push(c);
        }
        while (!stack.isEmpty()) {
            buffer.append(stack.pop());
        }
        return buffer.reverse().toString();
    }

    public String getMinorEncodedString(Stack<Character> stack) {
        StringBuffer buffer = new StringBuffer();
        boolean isLeftAppeared = false;
        while (!stack.isEmpty()) {
            char peek = stack.peek();
            if (isLeft(peek) && !isLeftAppeared) {
                isLeftAppeared = true;
                buffer.append(stack.pop());
                continue;
            }
            //如果没有出现过,那么入
            if (!isLeftAppeared) {
                buffer.append(stack.pop());
                continue;
            }
            //如果出现过,且不是beginner,入.
            if (!isBeginner(peek)) {
                buffer.append(stack.pop());
            } else {
                break;
            }
        }
        return buffer.reverse().toString();
    }

    public boolean isBeginner(char c) {
        return Character.isLetter(c) || isRight(c) || isLeft(c);
    }


    /**
     * @param s
     * @return
     */
    public String decodeMinorString(String s) {
        StringBuilder numberRecord = new StringBuilder();
        int index = 0;
        char[] cs = s.toCharArray();
        for (int i = 0; i < cs.length; i++) {
            if (isLeft(cs[i])) {
                index = i;
                break;
            }
            numberRecord.append(cs[i]);
        }
        String bInner = s.substring(index + 1, s.length() - 1);
        int number = Integer.parseInt(numberRecord.toString());
        StringBuilder decodedString = new StringBuilder();
        for (int i = 0; i < number; i++) {
            decodedString.append(bInner);
        }
        return decodedString.toString();
    }

    private boolean isLeft(char c) {
        return c == '[';
    }

    private boolean isRight(char c) {
        return c == ']';
    }