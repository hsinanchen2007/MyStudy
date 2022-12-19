### 解题思路
执行用时 :
12 ms
, 在所有 java 提交中击败了
17.54%
的用户
内存消耗 :
36.9 MB
, 在所有 java 提交中击败了
55.72%
的用户

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
         String s_res=s+t;
        HashMap<Character, Integer> map = new HashMap<>();
        char[] arr = s_res.toCharArray();
        for (char c : arr) {
            map.put(c, !map.containsKey(c)?1:(map.get(c)+1));
        }
        for (Character c : map.keySet()) {
            if(map.get(c)%2!=0){
                return c;
            }
        }
        return '-';

    }
}
```