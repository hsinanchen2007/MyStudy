[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_67_addBinary.java)

```java
    /**
     * 解题思路：
     * 从低位开始累加，注意两边字符串不一致，提高执行效率不要使用StringBuilder
     *
     * 执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
     * 内存消耗 :36 MB, 在所有 java 提交中击败了55.45%的用户
     *
     * @param a
     * @param b
     * @return
     */
    public String addBinary(String a, String b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        char[] result = new char[Math.max(i, j) + 1];
        int pos = result.length - 1;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a.charAt(i--) - '0';
            }
            if (j >= 0) {
                sum += b.charAt(j--) - '0';
            }
            //>>1 代表 /2，进位
            carry = sum >> 1;
            //sum & 0x01 ==> 进位后只取低位
            result[pos--] = (char) ((sum & 0x01) + '0');
        }
        if (carry > 0) { //最后有进位，直接进行数据拼接，防止数组越界
            return "1" + String.valueOf(result);
        }
        return String.valueOf(result);
    }
```