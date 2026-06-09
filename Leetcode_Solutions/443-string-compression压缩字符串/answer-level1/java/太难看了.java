### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int compress(char[] chars) {
        
        int left = 0;
        int right = 0;

        int ans = 0;

        while (right < chars.length) {
            while (right < chars.length && chars[left] == chars[right]) {
                right++;
            }
            chars[ans] = chars[left];
            if (left + 1 == right) {
                ans += 1;
            } else {
                String tmp = String.valueOf(right - left);
                chars[ans++] = chars[left];
                for (char c : tmp.toCharArray()) {
                    chars[ans++] = c;
                }
            }
            left = right;
        }
        return ans;
    }
}
```