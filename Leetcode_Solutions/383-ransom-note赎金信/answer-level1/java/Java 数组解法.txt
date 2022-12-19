### 解题思路
因为肯定只有26个字母，且全部是小写，直接全部存到数组，每次循环的时候就加或者减，最终的结果就是必须要数组每个元素的值==0或者小于0

### 代码

```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] count = new int[26];
        int i;
        if(magazine.length() < ransomNote.length())
            return false;
        for(i = 0; i < ransomNote.length(); i++){
            count[ransomNote.charAt(i) - 'a']++;
            count[magazine.charAt(i) - 'a']--;
        }
        while (i < magazine.length()){
            count[magazine.charAt(i++) - 'a']--;
        }

        for(int j : count){
            if(j > 0)
                return false;
        }
        return true;
    }
}
```