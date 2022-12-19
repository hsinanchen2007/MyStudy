### 解题思路
采用消消乐的思想，遍历字符串，如果set集合中有当前字符则消除它，没有就添加它，最终字符数量小于等于1说明它能完成对称

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        if (s==null||s.length()<1){
            return false;
        }
        char[] chars = s.toCharArray();
        HashSet<Character> characters = new HashSet<Character>();
        for (Character character : chars) {
            if (characters.contains(character)){
                characters.remove(character);
            }else {
                characters.add(character);
            }
        }
        return characters.size()<=1;
    }
}
```