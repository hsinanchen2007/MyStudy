### 解题思路
HashMap特点：k-v方式，不能存在重复的key
start,end 分别表示子字符串的起始位置
maxSize 表示最长子串
用 Map 的 key 和 value 分别存储遍历的字符和end+1（当前字符下标+1），表示下一个不重复的字符串的初始位置;
然后遍历字符串，如果没有重复就直接 put 进 map ，遇到重复的就改变 start，然后更新这个重复字符（key）的 value 值（HashMap中不能有重复的key）

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        int maxSize=0;
        Map<Character,Integer> map=new HashMap<>();
        for(int start=0,end=0;end<n;end++){
            char judge=s.charAt(end);
            if(map.containsKey(judge)){
                start=Math.max(start,map.get(judge));
            }
            map.put(judge,end+1);
            maxSize=Math.max(maxSize,end-start+1);
        }
        return maxSize;
    }
}
```