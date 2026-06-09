执行用时 :7 ms, 在所有 Java 提交中击败了98.73%的用户
内存消耗 :38.2 MB, 在所有 Java 提交中击败了88.15%的用户

1.定义一个获取罗马字符对应数字的静态方法，使用switch来获取字符对应数字
2.遍历从第一个字符开始，比较当前字符与下一字符对应数字大小，大于等于则加，否则减，最后一个字符直接加
```
class Solution {
    private static int getValue(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                throw new IllegalArgumentException("Illegal character");
        }
    }

    public int romanToInt(String s) {
        int result = 0, i = 0, n = s.length();
        while (i < n) {
            int current = getValue(s.charAt(i));
            if (i == n - 1 || current >= getValue(s.charAt(i + 1))) {
                result += current;
            } else {
                result -= current;
            }
            i++;
        }
        return result;
    }
}
```
