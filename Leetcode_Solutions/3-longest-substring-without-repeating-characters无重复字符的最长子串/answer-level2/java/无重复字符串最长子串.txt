![huadong.PNG](https://pic.leetcode-cn.com/8052728c9f73046a3308c3c18f7b2529c779b7f653456c10a2c30715ed131a87-huadong.PNG)
思路：使用滑动窗口原理，如上图所示。
字符串 abcabcbb
1.窗口从左第一个字符开始，向右挨个判断下一个字符是否重复，不重复，窗口右边界增加。同时子串长度
2.当出现第一个重复字符a时，窗口左边界向右收缩,直到不包含重复字符。记录子串长度
3.重复1,2。最终在多有长度中取最大值

java实现方法：
利用HashMap，将出现的字符不重复保存入HashMap中。
1)设窗口左边界pre=-1，子串长度max_len=0，初始化HashMap
2)用i遍历字符串，判断字符是否在HashMap中，如果存在,窗口左边界 pre = max(pre,index),index重复字符的首次出现位置
3）子串的长度 窗口右边界-窗口左边界（max_len = i-pre）
4)取所有子串的最长的值