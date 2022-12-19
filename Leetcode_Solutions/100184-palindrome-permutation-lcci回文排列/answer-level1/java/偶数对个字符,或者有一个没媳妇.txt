### 解题思路
string转字符数组, 将没有配对的存到map或其他容器中, 一旦有匹配的就从map中移除
最后判断map中的元素总数,如果超过1证明有多个字符没媳妇,无法对称

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        char[] chars = s.toCharArray();
        Map<Character, Boolean> temp = new HashMap<>();
        for (int i = 0; i < chars.length; i++) {
            if (temp.containsKey(chars[i])) {
                temp.remove(chars[i]);
            } else {
                temp.put(chars[i], true);
            }
        }
        return temp.size() <= 1;
    }
}
```