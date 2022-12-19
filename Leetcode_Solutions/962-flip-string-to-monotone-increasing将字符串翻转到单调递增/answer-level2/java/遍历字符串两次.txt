
思路：
以当前字符作为分割点，计算当前字符之前'1'的个数（需要翻转为‘0’的字符个数），以及当前字符之后'0'的个数（需要翻转为‘1’的字符个数），两者相加即为以当前字符串为分割点的翻转次数。
遍历数组，计算最小的翻转次数。
以第一个字符为分割点时，当前字符之前没有需要翻转的字符，当前字符之后需要翻转为‘1’的字符数为从第二个字符开始‘0’的个数。
向后遍历一位时，如果上一个字符为‘1’，则当前字符之前需要翻转为‘0’的字符+1；如果当前字符为‘0’，则当前字符之后需要翻转为‘1’的字符-1。
java代码如下：
class Solution {
    public int minFlipsMonoIncr(String S) {
        char[] chars = S.toCharArray();
        int reverseTo0 = 0;
        int reverseTo1 = this.count0(chars);
        int result = reverseTo0 + reverseTo1;
        for (int i = 1; i < chars.length; i++){
            if (chars[i - 1] == '1'){
                reverseTo0++;
            }
            if (chars[i] == '0'){
                reverseTo1--;
            }
            if (reverseTo0 + reverseTo1 < result){
                result = reverseTo0 + reverseTo1;
            }
        }
        return result;
    }
    private int count0(char[] chars){
        int count = 0;
        for (int i = 1; i < chars.length; i++){
            if (chars[i] == '0'){
                count++;
            }
        }
        return count;
    }
}