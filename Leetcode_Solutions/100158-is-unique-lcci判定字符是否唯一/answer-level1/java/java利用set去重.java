### 解题思路
利用set去重来判断是否有相同字符。
执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :37.4 MB, 在所有 Java 提交中击败了100.00%的用户
### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        Set set = new HashSet();
        for (int i = 0; i <astr.length() ; i++) {
            set.add(astr.charAt(i));
        }
        return set.size() == astr.length(); 
    }
}
```