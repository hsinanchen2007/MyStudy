执行用时 :6 ms, 在所有 Java 提交中击败了84.60%的用户
内存消耗 :41.6 MB, 在所有 Java 提交中击败了5.01%的用户

```
    public String reverseWords(String s) {
        StringBuilder stringBuilder = new StringBuilder();
        if(s == null || s.length() == 0)
            return s;
        char[] chars = s.toCharArray();
        int front = 0, back = 0;//front为要反转的单词的首字母，back为要反转的单词的末字母的下一位
        for (int i = 0; i < chars.length ; i++)
        {
            if (chars[i] != ' '){
                back++;
            }
            else{
                StringBuilder stringBuilder1 = new StringBuilder(s.substring(front,back));
                stringBuilder1.reverse();
                stringBuilder.append(stringBuilder1);
                stringBuilder.append(' ');
                front = back + 1; //当前back指向空格，所以front要从空格的下一个即下一个单词的首字母开始
                back = front;//front跟back同一线
            }
        } //此时最后一部分还没有反转，因为s的末尾不是空格，所以此时back应等于最后一个单词的末字母
        StringBuilder stringBuilder1 = new StringBuilder(s.substring(front,back));
        stringBuilder1.reverse();
        stringBuilder.append(stringBuilder1);
        return stringBuilder.toString();
    }
```
