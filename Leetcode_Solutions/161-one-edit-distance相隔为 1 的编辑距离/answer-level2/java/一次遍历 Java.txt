### 解题思路
用两个指针扫描时两个字符串。设置布尔值difference，其为true时表明扫描过的部分已经有区别，所以直接返回false。
- 首先判断边界情况：输入为null 为空字符串 长度相差超过一的情况。另外字符串相等的情况。
- 新写一个方法funcWithOrder,传入的两个字符串，第一个更长，或者两者一样长。
- funcWithOrder中，用两个指针（i,j）扫描字符串：
1. 字符相等时，i++,j++
2. 不相等时，若字符串一样长，则i++,j++
3. 否则（第一个字符串长度多一），则i++

### 代码

```java
class Solution {
    public boolean isOneEditDistance(String s, String t) {
        if(s==null || t==null) return false;
        if(s.length()==0 && t.length()==0) return false;
        if(s.equals(t)) return false;
        
        int n=s.length();
        int m=t.length();
        if(n-m==1 || n==m) return funcWithOrder(s,t);
        else if(n-m==-1) return funcWithOrder(t,s);
        return false;
    }
    private boolean funcWithOrder(String longstr,String shortstr){
        char[] s=longstr.toCharArray();
        char[] t=shortstr.toCharArray();
        int n=s.length;
        int m=t.length;
        int i=0,j=0;
        boolean difference=false;
        while(i<n && j<m){
            if(s[i]!=t[j]) {
                if(difference) return false;
                difference=true;
                if(m==n)  j++;
                i++;
            }else{
                i++;
                j++;
            }  
        }
        return true;
    }
}
```