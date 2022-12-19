解法一：思维：将int整数转化为字符串，再转化为char[]数组进行倒叙遍历

        String a = Integer.toString(x);
        int b = 1;
        if(a.charAt(0) == '-') {
            a = a.substring(1);
            b = -1;
        }
        char[] chars = a.toCharArray();
        char[] chars1 = new char[chars.length];
        for (int i = chars.length - 1; i >= 0; i--) {
            chars1[chars.length - 1 - i] = chars[i];
        }
        Long aLong = Long.valueOf(new String(chars1));
        if(aLong > Integer.MAX_VALUE || aLong < Integer.MIN_VALUE) {
            return 0;
        }
        return (int) (aLong * b);

解法二：将int整数对10进行取模取余。

        int term;
        long b = 0;
        while (x != 0) {
            term = x % 10;
            x = x / 10;
            b = b*10 + term;
        }
        if(b > Integer.MAX_VALUE || b < Integer.MIN_VALUE) {
            return 0;
        }
        return (int) b;  