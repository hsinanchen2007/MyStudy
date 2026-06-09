### 解题思路
set集合作为滑动窗口，左右指针是窗口边界

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set=new HashSet<>();
        int l=0,r=0;
        int len=s.length();
        int res=0;
        
        while(l<len&&r<len){
            if(!set.contains(s.charAt(r))){
                set.add(s.charAt(r++));
                res=Math.max(res,r-l);
            }else{
                set.remove(s.charAt(l++));
            }
        }
        return res;
    }
}
```