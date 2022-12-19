
    public int myAtoi(String str) {
        char[] chars = str.trim().toCharArray();
        if (chars.length <= 0) return 0;
        int number = 0;
        final int max = Integer.MAX_VALUE;
        final int min = Integer.MIN_VALUE;
        for (int i = 0; i < chars.length; i++) {
            if ((i == 0) && ((chars[i] == '-') || (chars[i] == '+'))) {
                continue;
            }
            if ((chars[i] >= '0') && (chars[i] <= '9')) {
                if (((number*10)/10) != number) {
                    number = min;
                    break;
                }
                if (number < Math.max(min, ((((number * (10)) + '0')) - chars[i]))) {
                    number = min;
                } else {
                    number = Math.max(min, ((((number * (10)) + '0')) - chars[i]));
                }
            } else {
                break;
            }
        }
        if (chars[0] != '-') {
            int temp = 0 - number;
            if (temp < 0) {
                number = max;
            } else {
                number = temp;
            }
        }
        return number;
    }