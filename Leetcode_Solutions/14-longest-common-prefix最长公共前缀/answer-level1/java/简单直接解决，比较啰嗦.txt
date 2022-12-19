### 解题思路
代码中已写，最直接的方法

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        //如果输入的字符串数组中没有元素时
        if(strs.length==0) return "";
        //字符串数组中只有一个元素时
        if(strs.length==1) return strs[0];
        //第一个字符串和第二个字符串的公共前缀
        String result=twoStringsCommonPrefix(strs[0],strs[1]);
        //如果字符串数组中有两个元素时
        if(strs.length==2){
                if(result.length()==0) return "";//无公共前缀
                return result;//有公共前缀
        }
        // 字符串数组中有多个元素时，将第一和第二个字符串的比较结果先与第三个字符串作比较，直到最后一个字符串
        for(int i=2;i<strs.length;i++){
            result=twoStringsCommonPrefix(result,strs[i]);
        }
        return result;
    }
    //函数功能：找到两个字符串中的公共前缀
    public String twoStringsCommonPrefix(String s1,String s2){
        String ss="";
        int m=s1.length();
        int n=s2.length();
        int k=m<n?m:n;
        for(int i=0;i<k;i++){
            char ch1=s1.charAt(i);
            char ch2=s2.charAt(i);
            if(ch1!=ch2) break;
            ss+=ch1;
        }
        return ss;
    }
}
```