### 解题思路
此处撰写解题思路
我是个小白，这道题上来的思路就是：从左到右缩短主串，并设一个计数器，一直到主串最前面的一部分子串恰好和子串匹配，就这么简单，但是用时和内存都太大了，看来还得努力学习！
### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        int i=0;int j=haystack.length();
        if(haystack.length()==0&&needle.length()!=0)return -1;
        if(haystack.equals(needle))return 0;
        while(i<j){
            if(haystack.indexOf(needle)==0){return i;}
            else{
                i++;
                haystack=haystack.substring(1,haystack.length());
            }
        }
        return -1;
    }
}
```