新手，刚进来2天，方法是split拆分后，for循环反方向放进stringBuffer，遇到空字符串就跳过，每个单词间隔一个空格拼接。
之后转string输出，切除最后一位的空格。
但是如果本身就没有长度，那么输出也是空白。
击败98%的用户，计算速度快。
有任何问题和不妥之处还请个为多多评论提醒，麻烦大家了。


class Solution {
    public String reverseWords(String s) {
        String[] someWords = s.split(" ");
        StringBuffer outStr = new StringBuffer();
        for (int i = someWords.length - 1; i >= 0; i--) {
            if(someWords[i].equals(""))
                continue;
            outStr.append(someWords[i]).append(" ");
        }
        if (outStr.length()==0)
            return "";
        return outStr.toString().substring(0, outStr.length() - 1);
    }
}