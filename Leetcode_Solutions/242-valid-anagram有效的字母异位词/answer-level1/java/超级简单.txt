### 解题思路
此处撰写解题思路
因为一共只有26个字符，所以定义一个有26个元素的数组，遍历两个字符串，话不多说，代码如下，一看就懂。
### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        int[]cnts=new int[26];
        for(int i=0;i<s.length();i++) cnts[s.charAt(i)-'a']++;
        for(int i=0;i<t.length();i++) cnts[t.charAt(i)-'a']--;
        for(int i=0;i<26;i++) if(cnts[i]!=0) return false;
        return true;
    }
}
```