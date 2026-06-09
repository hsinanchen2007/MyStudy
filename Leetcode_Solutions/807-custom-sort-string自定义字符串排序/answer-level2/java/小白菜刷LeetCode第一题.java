// ### 解题思路
// 啊啊啊啊终于跟着别人的思路写出来了,桶排序🐂🍺!小白菜也开始刷LeetCode!
// ### 代码

// ```java
class Solution { 
    public String customSortString(String S, String T) {
         char[] sArr = S.toCharArray();
        char[] tArr = T.toCharArray();
        char[] other=new char[200];
        int[] counts = new int[26];
        int othersize=0;
        for (int i = 0; i < tArr.length; i++) {
            char value = tArr[i];
            if (S.indexOf(value) != -1) {
                int index = value - 'a';
                if (counts[index] != 0) {
                    counts[index]++;
                } else counts[index] = 1;
            } else {
                other[othersize] = T.charAt(i);
                othersize++;
            }
        }
        
        StringBuilder stringBuffer = new StringBuilder();
        for (char c : sArr) {
            int f = counts[c - 'a'];
            StringBuffer s = new StringBuffer();
            for (int j = 0; j < f; j++) {
                s.append(c);
            }
            stringBuffer.append(s);
        }
        for (int i = 0; i < othersize; i++) {
            stringBuffer.append(other[i]);
        }
        return stringBuffer.toString();
    }
}
// ```