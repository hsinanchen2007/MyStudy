### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int [] words=new int[26];
        for(char s:ransomNote.toCharArray())
            words[s-'a']++;
        int [] a=new int[26];
        for(char s:magazine.toCharArray())
            a[s-'a']++;
        for(int i=0;i<26;i++)
        {
            if(a[i]<words[i])
                return false;
        }
        return true;
    }
}
```