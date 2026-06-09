### 解题思路


### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==0) return 0;
        if(s.length()==1) return 1;

        HashSet<Character> set = new HashSet<>(); //用hashset统计
        int maxLen=0; 
        for(int i=0;i<s.length();i++){
            for(int j=i; j<s.length();j++){
                char c = s.charAt(j);
                if(!set.contains(c)){ //无重复，则统计长度，加入到set
                    maxLen = Math.max(j-i+1, maxLen);
                    set.add(c); 
                    continue;
                }else{ //重复，退出循环，清空set
                    set.clear();
                    break;
                }
            }
            
        }
        return maxLen;
    }
}
```