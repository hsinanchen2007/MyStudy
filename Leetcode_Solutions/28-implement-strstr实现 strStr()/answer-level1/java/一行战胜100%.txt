解法一：一行解决
```
return haystack.indexOf(needle);
```

解法二：双指针法，优化了一个头尾判断，就可以过滤掉很多不符合的答案了。

```
class Solution {
    public int strStr(String haystack, String needle) {
        if("".equals(needle) || needle == null) return 0;
        int hLength = haystack.length();
        int nLength = needle.length();
        if(hLength < nLength) return -1;
        for(int i = 0; i < hLength; i++) {
            //判断头
            if(haystack.charAt(i) == needle.charAt(0)){
                //判断尾部
                if(hLength <= (i + nLength - 1)) continue;
                if(haystack.charAt(i + nLength - 1) == needle.charAt(nLength - 1)){
                    if(check(haystack, needle, i)){
                        return i;
                    }
                }
            }
        }
        return -1;
    }
    
    public boolean check(String haystack, String needle,int i){
        for(int j = i; j < needle.length() + i; j++) {
            if(haystack.charAt(j) != needle.charAt(j-i)) return false;
        }
        return true;
    }
    }
        
}
```
