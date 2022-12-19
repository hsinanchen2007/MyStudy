### 解题思路
此处撰写解题思路
去重单个的字符串，再合并字符串去重，如果合并后的字符串等于单个字符串说明是有相同的字符~
### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {

        if (s1==null && s2==null) return true;
        if (s1==null || s2==null) return false;
        if (s1.length()!=s2.length()) return false;

        int s1Len=Stream.of(s1).map(s -> s.split("")).flatMap(Arrays::stream).distinct().collect(Collectors.joining()).length();
        int s2Len=Stream.of(s2).map(s -> s.split("")).flatMap(Arrays::stream).distinct().collect(Collectors.joining()).length();
        int res=Stream.of(s1,s2).map(s -> s.split("")).flatMap(Arrays::stream).distinct().collect(Collectors.joining()).length();


        return (res==s1Len) && (res==s2Len);
    }
}
```