### 解题思路
运用哈希表存储指定字符和字符出现次数，因为回文结构中字符最多只能出现一次奇数，所以将全部偶数记入总长度，奇数全部减一之后记入总长度。最后返回总长度。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        char[] chars = s.toCharArray();
        Map<Character,Integer> charMap = new HashMap<>();
        System.out.println(chars.length);
        for(int i = 0; i < chars.length; i++) {
            if(charMap.containsKey(chars[i])){
                charMap.put(chars[i],charMap.get(chars[i])+1);
            }else{
                charMap.put(chars[i],1);
            }
        }
        boolean mid = true;
        int maxLength = 0;
        for (Character character : charMap.keySet()){
            if(charMap.get(character)%2 == 0){
                maxLength += charMap.get(character);
            }else{
                maxLength += charMap.get(character)-1;
                mid = false;
            }
        }
        if(mid){
            return maxLength;
        }else{
            return maxLength+1;
        }
    }
}
```