### 解题思路
递归逐个匹配，保存第一次匹配的位置，匹配失败后回归到匹配位置重新匹配。

### 代码

```java
class Solution {
    
    public  int strStr(String haystack, String needle) {
        if("".equals (haystack) && "".equals (needle)){
            return 0;
        }
        if(haystack == null || needle == null){
            return 0;
        }
        if("".equals (haystack) && !"".equals (needle)){
            return -1;
        }
        if(!"".equals (haystack) && "".equals (needle)){
            return 0;
        }
        char[] charsh = haystack.toCharArray ();
        char[] charsn = needle.toCharArray ();
        return strSearch (charsh,0,charsn,0,-1);
    }
    // 匹配到第一个字符后，修改为true
    private  boolean matched = false;
    /**
     *
     * @param haystack 源字符串
     * @param h 源字符串往后匹配的位置
     * @param needle 待匹配的字符串
     * @param n 待匹配字符串的匹配位置
     * @param pass 匹配的位置
     * @return
     */
    private  int strSearch(char[] haystack,int h, char[] needle,int n, int pass) {
        // 匹配完成 
        if(n == needle.length){
            return pass;
        }
        // 匹配失败
        if(h == haystack.length){
             return -1;
         }
         String hay = String.valueOf (haystack[h]);
         String nee = String.valueOf (needle[n]);

         if(hay.equals (nee)){
             n ++;
             if(!matched){ // 第一次匹配时，更新匹配位置
                 pass = h;
                 matched = true;
             }
         }else { // 匹配失败
             if(matched){  // 已经匹配到一部分
                 h = pass; // 重置元字符串匹配位置
                 n = 0;    // 从头开始匹配
             }
             matched = false;
             pass = -1;
         }
         h ++;
         return strSearch (haystack, h, needle, n, pass);
    }
}
```