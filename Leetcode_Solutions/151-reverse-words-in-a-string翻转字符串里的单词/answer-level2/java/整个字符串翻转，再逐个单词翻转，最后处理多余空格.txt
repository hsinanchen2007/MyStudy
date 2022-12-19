翻转字符串后；
使用左右指针进行单词的边界判断，然后旋转单词，期间记录空格数和单词数；
没有多余空格的字符串，单词数目-1=空格数，根据这个可以免去一些合理的字符串的处理；
有多余空格的字符串，做边界空格和单词之间空格的处理
```
class Solution {
    public String reverseWords(String s) { // 先翻转整个字符串，然后翻转单词，
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length - 1;
        reverse(chars, left, right);
        left = 0;
        right = 0;

        int emptyCount = 0;
        int wordsCount = 0;
        for (char c : chars) {
            if (c == ' ') {
                emptyCount++;
                if (left == right) {
                    left++;
                    right++;
                } else {
                    wordsCount++;
                    reverse(chars, left, right - 1);
                    right++;
                    left = right;
                }
            } else {
                right++;
                if (right == chars.length) {
                    wordsCount++;
                    reverse(chars, left, right - 1);
                }
            }
        }
        if (wordsCount == 0) {
            return "";
        }
        if (emptyCount == wordsCount - 1) { // 刚好没多余空格的情况
            return String.valueOf(chars);
        }
        // 所需空格是（单词数目-1）
        char[] newArr = new char[chars.length - emptyCount + (wordsCount - 1)];
        System.out.println(newArr.length);
        int newIndex = 0;
        boolean meetNotEmpty = false;
        for (char c : chars) {
            if (c == ' ') {
                if (meetNotEmpty && newIndex < newArr.length) { // 前面遇到非空的字符，加个空格
                    newArr[newIndex++] = c;
                    meetNotEmpty = false; // 还原状态
                }
            } else {
                meetNotEmpty = true;
                newArr[newIndex++] = c;
            }
        }
        return String.valueOf(newArr);
    }

    private static void reverse(char[] chars, int left, int right) {
        while (left < right) {
            chars[left] ^= chars[right];
            chars[right] ^= chars[left];
            chars[left] ^= chars[right];
            left++;
            right--;
        }
    }
}
```