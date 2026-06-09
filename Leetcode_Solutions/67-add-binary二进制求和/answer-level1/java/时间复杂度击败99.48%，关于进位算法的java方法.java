![1569750907152.jpg](https://pic.leetcode-cn.com/9fd027b4be7c8161f63bb458d32ca27aa999e5a9d387956afb8a17275238d58f-1569750907152.jpg)

下面是算法 PS：代码没有进行优化简化，直接贴上来了，很多冗余和纰漏还请指正！
```
    public static String addBinary(String a, String b) {
        char[] char_a = a.trim().toCharArray();
        char[] char_b = b.trim().toCharArray();
        int cLength = Math.max(char_a.length, char_b.length) + 1;
        int[] c = new int[cLength];
        int tag = 0;
        for (int i = 1; i <= cLength; i++) {
            if (i <= char_a.length && i <= char_b.length) {
                if (char_a[char_a.length - i] + char_b[char_b.length - i] + tag - (int) ('0') * 2 >= 2) {
                    c[c.length - i] = (char_a[char_a.length - i] + char_b[char_b.length - i] + tag - (int) ('0') * 2) % 2;
                    tag = (char_a[char_a.length - i] + char_b[char_b.length - i] + tag - (int) ('0') * 2) / 2;
                } else {
                    c[c.length - i] = char_a[char_a.length - i] + char_b[char_b.length - i] + tag - (int) ('0') * 2;
                    tag = 0;
                }
            } else {
                if (char_a.length > char_b.length && i <= char_a.length) {
                    c[c.length - i] = (char_a[char_a.length - i] + tag - (int) ('0')) % 2;
                    tag = (char_a[char_a.length - i] + tag - (int) ('0')) / 2;
                }
                if (char_b.length >= char_a.length && i <= char_b.length) {
                    c[c.length - i] = (char_b[char_b.length - i] + tag - (int) ('0')) % 2;
                    tag = (char_b[char_b.length - i] + tag - (int) ('0')) / 2;
                }
                if (i > char_a.length && i > char_b.length) {
                    c[c.length - i] = tag;
                }
            }
        }
        StringBuffer str5 = new StringBuffer();
        for (int s : c) {
            str5.append(String.valueOf(s));
        }
        String retVel = str5.toString();
        if (retVel.startsWith("0")) {
            retVel = retVel.substring(1);
        }
        return retVel;
    }
```

关于数字相加需要进位的问题，可以参见我另外一个题解，时间复杂度击败100%。
这类问题可以归结出一下特征：
说明：当前进行相加的数位我们称为考察位。
1:进位的数值我们用tag表示，对于两个数字相加的情况，tag只有0和1两种情况，表示不需要进位和需要进位。
2:当前考察位的计算后数值=（考察位1+考察位2+tag）%进制数； 计算后tag=（考察位1+考察位2+tag）／进制数。
3:根据具体情况倒叙遍历即可求出结果。
