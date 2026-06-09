### 解题思路
此处撰写解题思路
中心扩展算法， int len1=computelen(s,i,i);以位置i处的节点向两侧搜索，int len2=computelen(s,i,i+1);以位置i和i+1处的节点向两侧搜索。因为回文字符串要么以节点对称，要么以两个节点间的空格对称。

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        int start=0,end=0;
        if(s==null||s.length()<1)return "";
        for(int i=0;i<s.length();i++){
            int len1=computelen(s,i,i);
            int len2=computelen(s,i,i+1);
            int len=Math.max(len1,len2);
            if(len>end-start){
               start=i-(len-1)/2;
               end=i+len/2;
            }
        }
    
        return s.substring(start,end+1);
    }
    private int computelen(String s,int left,int right){
        while(left>=0&&right<s.length()&&s.charAt(left)==s.charAt(right)){
            left--;
            right++;
        }

        return right-left-1;
    }
}
```