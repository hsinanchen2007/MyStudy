具体思路：中心扩散（或者从两边以某点为中心收缩）注意到回文可能是abba这样的，这样回文中心就是bb，需要写一个中心扩散函数，左边一个指针，右边一个指针，这俩指针有可能初始阶段相重合（例如bcb中间的c），也有可能不重合（例如前面bb，则左右指针相差1），扩散函数的思路是，只要不超出字符串界限，并且左右两个指针位置字符始终相等，则继续扩散，直到边界或者两边不相等，扩散函数返回的是回文字符串的长度。而后在主函数里面，需要得到两个不同中心位置下的长度（也就是i,i和i,i+1），并作比较求最大值，并和当前保存下来的回文字符串最大位置start，end的距离相比较，如果比它大，则更新start，end的位置，否则不更新。更新start，end的方法在代码中，保证更新后start，end之间距离为新的长度。最后返回start和end标记的最长回文字符串。
```
//借鉴于https://blog.csdn.net/twt936457991/article/details/91868076
public String longestPalindrome(String s){
         if (s == null || s.length() < 1) return "";
         int start = 0;
         int end = 0;
         for (int i = 0; i<s.length();i++){
             int len1 = expandAroundCenter(s,i,i);
             int len2 = expandAroundCenter(s,i,i+1);
             int len = Math.max(len1,len2);
             if(len>end - start){
                 start = i - (len-1)/2 ;
                 end = i + len/2;
             }
         }
         return s.substring(start,end+1);
    }
    public int expandAroundCenter(String s, int left, int right){
        int L = left;
        int R = right;
        while(L>=0 && R<=s.length()-1 && s.charAt(L)==s.charAt(R)){
            L--;
            R++;
        }
        return R - L + 1;
    }
```

