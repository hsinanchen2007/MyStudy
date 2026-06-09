[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_65_isNumber.java)

```java
    /**
     * 解题思路：
     * 本题最大的难点在于各种情况互相依赖，后面想了想，每种情况只关注自己该放的位置就可以了
     * caseTest有1400多个，情况比较多，导致提交多次，比较全的caseTest参考上面链接
     * 1、输入左右可能有空格，先去除左右空格
     * 2、对于length==1的情况，直接判断是否是0-9
     * 3、添加几个计数器减少循环次数（e的个数、小数点的个数、+,-的个数）
     * 4、开始循环
     * 5、对于数字：直接continue，01都是满足条件的
     * 6、对于+\-：最多出现2次（最前面和e的后面），出现直接可以跟数字和.
     * 7、对于e：最多出现1次，出现的位置不能在头和尾
     * 8、对于.：最多1个点，如果之前出现过 e ,则后续不允许有点，出现以后其前后至少有一个数字 .1
     *
     *
     * 执行用时 :3 ms, 在所有 java 提交中击败了94.47%的用户
     * 内存消耗 :36 MB, 在所有 java 提交中击败了89.15%的用户
     * @param s
     * @return
     */
    public boolean isNumber(String s) {
        //1、输入左右可能有空格，先去除左右空格
        s = s.trim();
        //2、对于length==1的情况，直接判断是否是0-9
        if (s.length() == 0) return false;
        if (s.length() == 1) {
            return isNumber(s.charAt(0));
        }

        //3、添加几个计数器减少循环次数
        //e的个数
        int eCount = 0;
        //小数点的个数
        int dCount = 0;
        //+,-的个数
        int oCount = 0;

        //4
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (isNumber(c)) {
                //5：直接continue，01都是满足条件的
            } else if (c == '-' || c == '+') {
                //6：最多出现2次（最前面和e的后面），出现直接可以跟数字和.
                if (oCount > 1) return false;
                //对满足条件的取反
                if (!((i == 0 && (isNumber(s.charAt(i + 1)) || s.charAt(i + 1) == '.')) || (i > 0 && i < s.length() - 1 && s.charAt(i - 1) == 'e'))) {
                    return false;
                }
                oCount++;
            } else if (c == 'e') {
                //7、对于e：最多出现1次，出现的位置不能在头和尾
                if (eCount > 0) return false;
                if (!(i > 0 && i < s.length() - 1)) {
                    return false;
                }
                eCount++;
            } else if (c == '.') {
                //8、对于.：最多1个点，如果之前出现过 e ,则后续不允许有点，出现以后其前后至少有一个数字 .1
                if (dCount > 0 || eCount > 0) return false;
                //点前后必须有一个数字
                if (i == 0) {
                    if (!isNumber(s.charAt(i + 1)))
                        return false;
                } else if (i == s.length() - 1) {
                    if (!isNumber(s.charAt(i - 1)))
                        return false;
                } else {
                    if (!isNumber(s.charAt(i + 1)) && !isNumber(s.charAt(i - 1))) {
                        return false;
                    }
                }
                dCount++;
            } else {
                return false;
            }
        }

        return true;
    }

    private boolean isNumber(char c) {
        return c >= '0' && c <= '9';
    }
```