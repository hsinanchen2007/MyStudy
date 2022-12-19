两种解法如下，我这里跑，用桶比用哈希表快50%。。。

思路一：使用hashmap + 两次遍历。

```java
class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(!map.containsKey(c)) {
                map.put(c, 1);
            }else {
                map.put(c, map.get(c) + 1);
            }
        }
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(map.containsKey(c)) {
                if(map.get(c) == 1) {
                    return i;
                }
            }
        }
        return -1;
    }
}
```

思路二：使用桶 + 两次遍历。

```java
class Solution {
    public int firstUniqChar(String s) {
        int[] buckets = new int[26];
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            buckets[c - 'a']++;
        }
        for(int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'a';
            if(buckets[index] == 1) {
                return i;
            }
        }
        return -1;
    }
}
```