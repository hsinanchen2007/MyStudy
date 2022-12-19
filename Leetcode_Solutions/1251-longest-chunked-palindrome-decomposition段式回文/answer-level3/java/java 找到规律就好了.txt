class Solution {
  /*
   *实际上知道开始的第一个字母 就可以知道从哪开始了 因为倒序找这个字母的位子 然后从这个位置到最后就是 i 的起始值 
   *比如 ghigabcdefhelloadamhellobcdefghiga 
   *g开头 所以倒序g出现的位置是2 或 5 所以第一个可能字符串的长度就是2或5
  */
    public int longestDecomposition(String text) {
        int index = text.length()-1,index1 , res = 0, i = 0;
        do {
            index1 = text.lastIndexOf(text.charAt(i),index);
            String str = text.substring(index1);
            if (text.startsWith(str)) {
                if (text.equals(str)) {
                    res+=1; break;
                }
                res+=2;
                text = text.substring(str.length(), text.length()-str.length());//去掉第一个出现的字符串
                index = text.length()-1;
                System.out.println(text);
                continue;
            } else {
                index = index1-1;
            }
        } while (text.length() > 0);
      return res;
    }
}