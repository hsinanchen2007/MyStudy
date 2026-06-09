### 解题思路
不用哈希表，用数组

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] tmpList = count(chars);
        int res = 0;
        for(String s:words){
            res += helper(tmpList,s);
        }
        return res;
    }
    public int[] count(String s){
        int[] res = new int[26];
        for(int i = 0;i<s.length();i++)
            res[s.charAt(i)-'a']++;
        return res;
    }
    public int helper(int[] t,String s){
        int[] tmp = new int[26];
        for(int i = 0;i<s.length();i++){
            int p = s.charAt(i)-'a';
            tmp[p]++;
            if(tmp[p]>t[p])
                return 0;
        }
        return s.length();
    }
}
```