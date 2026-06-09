### 解题思路
利用两个set
返回判断两个set和字串长度
### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        Set set1 = new HashSet();
        Set set2 = new HashSet();
        for (int i = 0; i < s1.length() ; i++) {
            set1.add(s1.charAt(i));
        }
        for (int i = 0; i < s2.length() ; i++) {
            set2.add(s2.charAt(i));
        }
        return set1.equals(set2) && s1.length() == s2.length();
    }
}
```