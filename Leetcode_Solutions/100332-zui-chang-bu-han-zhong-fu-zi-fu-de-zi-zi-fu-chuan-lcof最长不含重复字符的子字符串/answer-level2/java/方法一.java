### 解题思路
此处撰写解题思路
初始化变量maxlength用于表示最大子串的长度。
currlength用于记录当前子串的长度。
首先将字符串转换为数组，从头开始循环，若子串没有包含当前字符，则将当前字符拼接在子串之后，且且记录子串的长度加一，若当前子串的长度大于maxlength，则更新maxlength；
若子串中已经包含当前字符，则求得子串中当前字符的位置，然后从此位置开始将子串截断，重新取得不重复子串，再将当前字符拼于子串后边，同时记录当前子串的长度，若当前子串的长度大于maxlength，则更新maxlength；
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int length = s.length();
        int maxlength = 0;
        int currlength = 0;
        String sub = "";
        char[] c=s.toCharArray();
        for(int i=0;i<length;i++){
            if(sub.indexOf(c[i])!=-1){
            	sub = sub.substring(sub.indexOf(c[i])+1);
            	sub = sub + c[i]+"";
            	currlength = sub.length();
            	if(currlength>maxlength){
            		maxlength = currlength;
            	}
            }else{
            	sub = sub+c[i];
            	currlength++;
            	if(currlength>maxlength){
            		maxlength = currlength;
            	}
            }
        }
        return maxlength;
    }
}
```