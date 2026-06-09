![2020021901.PNG](https://pic.leetcode-cn.com/e1899acaeb99bf2aabe6a0bdfbc94b26f2a4af1dde98fc8329fed74c9eca41b1-2020021901.PNG)
### 解题思路
声明指针right,指针right往前遍历; 
声明哈希表recMap,其Key为Character(即字符类型),Value为该字符在字符串对应的索引right;
recMap.put(s.charAt(right),right);
声明左指针left(初始为0),left记录重复字符对应的索引值加1;
当recMap中的key值出现重复值时,
计算当前不含重复字符子串的长度len,len=right-left,比较结果out与len的大小,将较大值赋给out;
此时,要找到出现的重复字符在哈希表中的索引值index = recMap.get(s.charAt(right)),若index+1>left,则更新left,否则不更新left;
接着,更新当前重复字符在哈希表中的索引值,即将当前新索引值放入哈希表中;
遍历完字符串,返回输出结果out.
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int out=0;
        int left=0;
        int right=0;
        Map<Character,Integer> recMap = new HashMap<>();
        while(right<s.length()){
            if(!recMap.containsKey(s.charAt(right))){
                recMap.put(s.charAt(right),right);
            }else{
                if(right-left>out){
                    out=right-left;
                }
                if(recMap.get(s.charAt(right))+1>left) {
                	left = recMap.get(s.charAt(right))+1;
                }              
                recMap.put(s.charAt(right),right);
            }
            right++;
        }
        if(right-left>out){
            out = right-left;
        }
        return out; 
    }
}
```