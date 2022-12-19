Java中的String是不可变对象，在不使用StringBuilder的情况下，可以将其转成char数组再做原地处理。
受数组移位的启发，数组中的单词翻转可以使用这种操作：
1.反转整个数组，此时每个单词本身也颠倒了
2.将每个单词再反转
3.去掉多余空格
在遍历每个单词的过程中，使用双指针做滑动窗口。此外整个翻转过程可以继续优化，将去掉空格的操作合并入步骤2：
1.反转整个数组
2.将每个单词连同之前的空格一起作为子数组反转
这时，每一次单词反转都会将其之前的空格移到后面，然后在该单词后留一个空格，用一个变量preWhiteIndex记录该位置，再将下一个单词连同其之前原有的空格和上一个单词反转后的空格一起作为子数组反转，如此反复，直到数组尾。
最后，所有多余空格全部被移到了数组尾，将该数组包含结果部分的子数组转为String返回即可。

```
class Solution {
    public String reverseWords(String s) {
        char[] c = s.toCharArray();
        reverse(c, 0, c.length - 1);
        int preWhiteIndex = 0;
        for (int i = 0, j = 0; j < c.length;) {
            while (i < c.length && c[i] == ' ') i++; // i为反转后的char数组的每一个单词的首字符位
            j = i;
            while (j < c.length && c[j] != ' ') j++; // j为反转后的char数组的每一个单词的末字符的下一位
            reverse(c, preWhiteIndex, j - 1); // 将当前单词连同之前的空白符一起反转
            preWhiteIndex += j == i ? 0 : j - i + 1; // 下一个单词要放到的起始位。字符串末尾有多个连续空格时，不更新preWhiteIndex
            i = j;
        }
        return String.valueOf(c, 0, preWhiteIndex - 1 < 0 ? 0 : preWhiteIndex - 1); // 输入""或纯空白字符串时preWhiteIndex取0
    }
    
    private void reverse(char[] c, int start, int end) {
        while (start < end) {
            char tmp = c[start];
            c[start++] = c[end];
            c[end--] = tmp;
        }
    }
}
```
