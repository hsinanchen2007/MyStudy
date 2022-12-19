### 解题思路
简单题，无非就是计算两个字符串重复的字符个数，再用字符串长度煎一下就可以了
### 代码

```java
class Solution {
    public int minSteps(String s, String t) {
        int[] a = new int[26];
        int[] b = new int[26]; 
        for (int i = 0; i < s.length(); i++) {
            a[s.charAt(i) - 'a']++;
            b[t.charAt(i) - 'a']++;
        } 
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            while (a[i] > 0 && b[i] > 0) {
                sum++;
                a[i]--;
                b[i]--;
            }
        }
        return t.length() - sum;
    }
}
```