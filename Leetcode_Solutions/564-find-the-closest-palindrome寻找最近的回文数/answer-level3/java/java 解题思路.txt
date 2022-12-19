```
public class Solution2 {

    public static void main(String[] args) {
        Solution2 solution2 = new Solution2();
        System.out.println(solution2.nearestPalindromic("10"));
    }

    // 题目要求最大是18位. 用Long 足够表示数字
    public String nearestPalindromic(String n) {
        // 处理特殊值 1位数
        if (n.length() == 1) {
            return String.valueOf(Math.abs(Long.parseLong(n) - 1));
        }
        // 原始数据
        Long num = Long.parseLong(n);
        // 原始数据直接 转回文
        Long huiwen = Long.parseLong(huiwen(n));
        // 从中间点数字 +1 再转回文 比如 9999 -> 10099 -> 100001
        Long huiwenAdd1 = Long.parseLong(midAdd1(n));
        // 从中间点数字 -1 再转回文 比如 10001 -> 9901 -> 9999
        Long huiwenMin1 = Long.parseLong(midMin1(n));
        // 找寻差值最小的数字
        Long res = 0L;
        Long abs = Long.MAX_VALUE;
        if (!huiwen.equals(num)) {
            res = huiwen;
            abs = Math.abs(huiwen - num);
        }
        long add1Abs = huiwenAdd1 - num;
        if (add1Abs < abs) {
            abs = add1Abs;
            res = huiwenAdd1;
        }
        long min1Abs = num - huiwenMin1;
        if (min1Abs <= abs) {
            abs = min1Abs;
            res = huiwenMin1;
        }
        return res.toString();
    }

    public String midAdd1(String n) {
        char[] chars = n.toCharArray();
        int mid = chars.length % 2 == 0 ? chars.length / 2 - 1 : chars.length / 2;
        for (int i = mid; i > -1; i--) {
            if (chars[i] == '9') {
                chars[i] = '0';
            } else {
                chars[i] += 1;
                break;
            }
        }
        if (chars[0] == '0') {
            char[] newChars = new char[chars.length + 1];
            newChars[0] = '1';
            System.arraycopy(chars, 0, newChars, 1, chars.length);
            return huiwen(new String(newChars));
        } else {
            return huiwen(new String(chars));
        }
    }

    public String midMin1(String n) {
        char[] chars = n.toCharArray();
        int mid = chars.length % 2 == 0 ? chars.length / 2 - 1 : chars.length / 2;
        for (int i = mid; i > -1; i--) {
            if (chars[i] == '0') {
                chars[i] = '9';
            } else {
                chars[i] -= 1;
                break;
            }
        }
        if (chars[0] == '0') {
            char[] newChars = new char[chars.length - 1];
            newChars[0] = '9';
            System.arraycopy(chars, 1, newChars, 1, chars.length - 2);
            return huiwen(new String(newChars));
        } else {
            return huiwen(new String(chars));
        }
    }

    public String huiwen(String n) {
        char[] chars = n.toCharArray();
        int mid = chars.length / 2;
        for (int i = 0; i < mid; i++) {
            chars[chars.length - 1 - i] = chars[i];
        }
        return new String(chars);
    }
}
```