首先放答案，该方法采用的是暴力破解法。
```
class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        String rev = new StringBuffer(s).reverse().toString();
        for (int i = 0; i < n; i++){
            if (s.substring(0, n - i).equals(rev.substring(i))){
                return rev.substring(0, i) + s;
            }
        }
        return "";
    }
}
```

题解：对于指定的字符串s，例如"abcbabcab"，我们需要找到从开头起的最大回文子串，这里就是"abcba"，剩下的是"bcab"，我们需要在左边添加对应的逆反字符串"bacb"，来拼接成回文串。

因此，我们首先将s反转，得到“bacbabcba”,我们可以通过s[0:n-i] == rev[i]来找到原本s从最左边起的最长的回文子串。这里是"abcba" == "abcba"。
找到之后，我们就将rev[0:i]作为s[n-i:]所需要的逆序字符串和原本的s进行拼接，也就是将"bacb"拼接到原本的"abcbabcab"之中，最终获得"bacbabcbabcab"，也就是我们需要的最短回文串。