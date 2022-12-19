### 解题思路

1、一个for循环，要考虑每个字母向两边扩展之后的的对称特性，就是代码中的getlen(String s,int l,int r)方法
2、考虑两种情况：aba、abba 。
3、sta = i - (len3-1)/2+1;  这一步比较难理解，其实主要是分两步：
    （1）aba 情况：sta = i - (len1)/2 ;  
    （2）abba 情况 ：sta = i - (len2)/2+1;  
   end都是一样的，


### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if (s==null && s.length() ==0) return "";
        int sta =0;
        int end =0;
        for (int i=0;i<s.length();i++) {
            int len1 = getlen(s,i,i);
            int len2 = getlen(s,i,i+1);

            int len3 = len1 > len2 ? len1:len2;

        if ((end-sta+1)<len3) {
// 这一步其实有点恶心，自己也是想的折中的方法，其实可以逻辑简单一点，但代码就复杂了
// 这一步其实可以用两个if来判断，如果似乎len1 zui                
                sta = i - (len3-1)/2+1;  

                end = i + len3/2;
        } 
}
        return s.substring(sta,end);
    }

// 得到长度
    public int getlen(String s,int l,int r){
        while (l>=0 && r<s.length() && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }
        return r-l+1;
    }
}
```