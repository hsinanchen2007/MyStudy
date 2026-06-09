解题思路：
设当前为第N位
每位的数字 * 26的N-1次方
总和即为26进制的数

class Solution {

    public int titleToNumber(String s) {
        int len = s.length();
        int res = 0;
        for (int i = 0; i < len; i++) {
            int curNum = s.charAt(len - 1 - i) - 'A' + 1;
            res += curNum * Math.pow(26, i);
        }
        return res;
    }
}