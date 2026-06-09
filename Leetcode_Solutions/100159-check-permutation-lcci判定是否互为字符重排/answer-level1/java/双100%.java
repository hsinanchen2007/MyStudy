### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        int []num=new int[26];
        if(s1.length()!=s2.length())
        return false;
        for(int i=0;i<s1.length();i++){
        num[s1.charAt(i)-'a']++;
        num[s2.charAt(i)-'a']--;
        }
        for(int i=0;i<num.length;i++){
            if(num[i]!=0)
            return false;
        }
        return true;
    }
}
```