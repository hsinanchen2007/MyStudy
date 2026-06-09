103 / 103 个通过测试用例
状态：通过
执行用时：13 ms
内存消耗：41.8 MB

中心扩容法
package letcode;

public class 最长回文子串 {

    public String longestPalindrome(String s) {
        if (s==null || s.isEmpty()) {
            return new String();
        }
        if (s.length()==1) {
            return s;
        }
        char[] chars = s.toCharArray();
        String res = new String();
        int max = 0;
        int k = 1;
        //每个点作为中心进行遍历
        for (int i = 1; i < chars.length; i++) {
            while (i+k<chars.length && i-k>=0 && chars[i-k] == chars[i+k] ) {
                k++;
            }
            k--;
            if (k>max) {
                max = k ;
                res = s.substring(i-k ,i+k+1);
            }
            k = 1;
        }
        //当前点和右边的点的空隙作为中心进行遍历
        k = 0;
        for (int i = 1; i < chars.length; i++) {
            while (i+k<chars.length && i-k-1>=0 && chars[i-k-1] == chars[i+k] ) {
                k++;
            }
            if (k>max) {
                max = k ;
                res = s.substring(i-k ,i+k);
            }
            k = 0;
        }
        if (max==0) {
            res = String.valueOf(s.charAt(0));
        }
        return res;
    }

    public static void main(String[] args){
        最长回文子串 a = new 最长回文子串();
        String res = a.longestPalindrome("abcdef");
        System.out.println(res);
    }

}



