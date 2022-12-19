### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] sCount=count(s);
        int[] tCount=count(t);
        for(int i=0;i<26;i++){
            if(sCount[i]!=tCount[i]){
                return false;
            }
        }
        return true;
    }
    
    private int[] count(String s){//应用hash思想
        int[] res=new int[26];
        for(int i=0;i<s.length();i++){
            res[s.charAt(i)-'a']++;
        }
        return res;
    }
}
```