### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        int[] ch1 = new int[26];
        int[] ch2 = new int[26];
        for(int i=0;i<s1.length();i++){
            ch1[s1.charAt(i)-'a']+=1;
        }
        for(int i=0;i<s2.length();i++){
            ch2[s2.charAt(i)-'a']+=1;
        }
        for(int i=0;i<26;i++){
            if(ch1[i]!=ch2[i]){
                return false;
            }
        }
        return true;
    }
}
```