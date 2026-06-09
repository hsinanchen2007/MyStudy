### 解题思路
此处撰写解题思路
滑动窗口的使用，对于数组和字符串，可以使用ij，初始i==j，来标记当前遍历的字符串。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len=s.length();
        int sum=0,i=0,j=0;
        Set<Character> set =new HashSet<>(); 
        while(i<len&&j<len){
            if(!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));
                sum=Math.max(set.size(),sum);
            }
            else{
                set.remove(s.charAt(i++));
            }

        }
        return sum;

    }
}
```