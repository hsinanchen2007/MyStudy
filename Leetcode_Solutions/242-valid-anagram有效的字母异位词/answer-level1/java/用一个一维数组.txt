### 解题思路
此处撰写解题思路
创建一个一维数组长度26，下标代表a-z
然后遍历字符串，s的字符加1，t的字符减1
最后检验count数组是否全部为零 不是就false 是就true

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] count = new int[26];
        for (char ch: s.toCharArray()) {
            count[ch-'a']++;
        }
        for (char ch: t.toCharArray()) {
            count[ch-'a']--;
        }
        for (int value : count) {
            if (value != 0) {
                return false;
            }
        }
        return true;
    }
}
```