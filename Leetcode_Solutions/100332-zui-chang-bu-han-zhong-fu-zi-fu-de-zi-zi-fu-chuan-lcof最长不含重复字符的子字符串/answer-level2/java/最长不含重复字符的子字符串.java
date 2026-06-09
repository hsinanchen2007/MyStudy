### 解题思路
采用一个HashMap，建立起每个字符和下标的对应关系；
比如abbca,第一个a的位置是0，第二次出现a的位置是4；
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] ch = s.toCharArray();
        int n = ch.length,count=0;
        Map<Character,Integer> map = new HashMap<>();
        for(int i=0,j=0;j<n;j++){
            if(map.containsKey(ch[j])){
                i = Math.max(map.get(ch[j]),i);
            }
            count =  Math.max(count,j-i+1);
            map.put(ch[j],j+1);
        }
        return count;
    }
}
```