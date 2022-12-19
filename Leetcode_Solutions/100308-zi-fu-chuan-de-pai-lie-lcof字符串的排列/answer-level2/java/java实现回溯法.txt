### 解题思路
1、第一个字符的可能性是String中所有的字符（去重后）;
2、第一个字符固定后，求剩下字符的所有排列；
3、递归求出剩下字符的所有排列，递归的结束条件是字符串只有一个字符了；
### 代码

```java
class Solution {
    public String[] permutation(String s) {
        if (s.length() <= 1) {
            return new String[] {s};
        }
        List<String> res = new ArrayList<>();
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            if (!set.contains(s.charAt(i))) {
                set.add(s.charAt(i));
                String[] childern = permutation(new StringBuilder(s).deleteCharAt(i).toString());
                for (String child: childern) {
//                    System.out.println(new StringBuilder(child).insert(0, s.charAt(i)).toString());
                    res.add(new StringBuilder(child).insert(0, s.charAt(i)).toString());
                }
            }
        }
        return res.toArray(new String[]{});
    }
}
```