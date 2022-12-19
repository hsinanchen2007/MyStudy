### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            int cur = map.get(s.charAt(i));
            int next = i+1 < s.length()? map.get(s.charAt(i+1)): 0;
            ans = ans + (cur < next? -cur: +cur); 
        }
        return ans;
    }
}
```