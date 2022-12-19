### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
    int[] t1 = new int[26],t2 = new int[26];
    for(int i=0;i<26;i++)
    {
        t1[i] = t2[i] = 0;
    }
    if(s1.length() != s2.length()) return false;
    for(int i=0;i<s1.length();i++){
        int a = s1.charAt(i)-'a';
        int b = s2.charAt(i)-'a';
        t1[a]++;
        t2[b]++;
    }
    for(int i=0;i<26;i++) if(t1[i] != t2[i]) return false;
    return true;
    }
}
```