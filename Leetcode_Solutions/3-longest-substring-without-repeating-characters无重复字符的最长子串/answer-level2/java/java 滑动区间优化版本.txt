### 解题思路
    假设我们定义[i,j]为无重复的子串，同时我们用Map<Character,Integer>表示已经存入的字符及位置
    int maxLength = 0;
    Map<Character,Integer> map = new HashMap<Character,Integer>();
    那么如果永远都没有重复
    for(int i = 0,j=0;j<s.length;j++){
        char currentChar = s.charAt(j);
        maxLength = Math.max(j-i+1,maxLength);       
        map.put(currentChar,j+1);
    }

    //当有重复字符时候,找到重复字符开始的位置
    if(map.containsKey(currentChar)){
        i = Math.max(i,map.get(currentChar));
    }
    

### 代码

```java
class Solution {

    public int lengthOfLongestSubstring(String s) {
        int i = 0,j = 0;
        int maxLength = 0;
        Map<Character,Integer> map = new HashMap<>();
        int lastIndex = s.length()-1;
        for(;j<=lastIndex;j++){
            char currentChar = s.charAt(j);
            if(map.containsKey(currentChar)){
                 i = Math.max(map.get(currentChar),i);
            }
            maxLength = Math.max(maxLength,j-i+1);
            map.put(currentChar,j+1);
        }
        return maxLength;
    }
}
```