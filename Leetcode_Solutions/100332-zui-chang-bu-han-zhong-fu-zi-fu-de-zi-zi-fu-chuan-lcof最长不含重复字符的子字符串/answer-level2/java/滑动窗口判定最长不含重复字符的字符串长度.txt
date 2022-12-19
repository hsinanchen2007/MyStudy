### 解题思路
* 设置从left到i的一个窗口
* 判断该窗口中是否有字符重复
    * 如果没有重复
        * `i++` 最长不重复长度`longest=Math.max(longest,i-left) //i-left为当前窗口大小`
    * 如果有重复  
        * `left++` 左指针右移动，直到没有重复的窗口
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.equals(""))
            return 0;
        int longest=1;
        int left=0;
        for(int i=1;i<s.length();){
            if(judge(s,left,i-1,s.charAt(i))){
                i++;
                longest=Math.max(longest,i-left);
            }
            else{
                left++;
            }
        }
        return longest;
    }
    private static boolean judge(String s,int left,int right,char c){
        for(int i=left;i<=right;i++){
            if(s.charAt(i)==c){
                return false;
            }
        }
        return true;
    }
}
```