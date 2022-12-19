直接模拟
技巧:使用同长度的数组存放压缩结果,如果压缩结果超出存放数组的大小,就退出返回原来字符串,,否则返回压缩后的字符串.
```
class Solution {
    public String compressString(String S) {
        char[] cs = new char[S.length()];
        int k = 0;
        for (int i = 0; i < S.length() && k < cs.length; ) {
            cs[k++] = S.charAt(i);
            int len = 0;
            for (int j = i; j < S.length(); j++) {
                if (S.charAt(j) == S.charAt(i)) len++;
                else break;
            }
            char[] ns = Integer.toString(len).toCharArray();
            for (int n = 0; n < ns.length && k < cs.length; k++, n++) {
                cs[k] = ns[n];
            }
            i = i + len;
        }
        if (k < cs.length) return new String(cs, 0, k);
        return S;
    }
}
```
