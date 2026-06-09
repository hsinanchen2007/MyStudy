### 解题思路
首先把字符存入哈希表，然后对哈希表遍历，如果是偶数就直接加上，奇数减1再加，最后判断长度，防止超过字符串的长度

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        Map<Character,Integer> map = new HashMap<>();
        int count = 0;
        for(char c : s.toCharArray()){
            map.put(c,map.getOrDefault(c,0) + 1);
        }
        for(char c : map.keySet()){
            if(map.get(c)%2 == 0){
                count += map.get(c);
            }else{
                count += map.get(c)-1;
            }
        }
        return count == s.length() ? count : count + 1;
    }
}
```