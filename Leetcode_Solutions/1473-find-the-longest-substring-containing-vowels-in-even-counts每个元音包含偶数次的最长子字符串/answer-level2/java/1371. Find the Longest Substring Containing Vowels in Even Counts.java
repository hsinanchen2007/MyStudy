### 解题思路
使用位运算 将奇偶分别用10两种状态表示 并用hashmap记录之前走过的状态 遇到相同状态则说明之间的substring为符合题目的substring

### 代码

```java
class Solution {
    public int findTheLongestSubstring(String s) {
        int key = 0;

        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(key, -1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            char c = s.charAt(i);
            if (getID(c) >= 0) {
                key ^= (1 << getID(c));
            }

            if (map.containsKey(key)) {
                ans = Math.max(ans, i - map.get(key));
            } else {
                map.put(key, i);
            }

        }

        return ans;

    }

    private int getID(char c) {
        if (c == 'a') {
            return 0;
        } else if (c == 'e') {
            return 1;
        } else if (c == 'i') {
            return 2;
        } else if (c == 'o') {
            return 3;
        } else if (c == 'u') {
            return 4;
        } else {
            return -1;
        }
    }
}
```