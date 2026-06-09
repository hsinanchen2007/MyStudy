从代码上面来谁最容易理解的写法
    public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        if (s.charAt(0) == '0') {
            return 0;
        }
        char[] jChars = s.toCharArray();
        return decode(jChars, jChars.length - 1);
    }

    public int decode(char[] jChars, int index) {
        if (index <= 0)
            return 1;
        int count = 0;
        char curr = jChars[index];
        char prev = jChars[index - 1];

        if (curr >= '1' && curr <= '9') {
            count = decode(jChars, index - 1);
        }
        if (prev == '1' && curr >= '0' && curr <= '9') {
            count = count + decode(jChars, index - 2);
        }
        if (prev == '2' && curr >= '0' && curr <= '6') {
            count = count + decode(jChars, index - 2);
        }
        return count;
    }