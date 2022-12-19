### 解题思路
1.将目标字符串排序
2.依次截取字符串，然后字符串排序，和排序后的目标字符串排序
3.满足条件加到结果list里

### 代码

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        char[] chars = p.toCharArray();
        Arrays.sort(chars);
        String paixu = String.valueOf(chars);

        List<Integer> results = new ArrayList<>();
        for (int i = 0; i < s.length() - p.length()+1; i++) {
            char[] chars1 = s.substring(i, i + p.length()).toCharArray();
            Arrays.sort(chars1);
            if (String.valueOf(chars1).equals(paixu)) {
                results.add(i);
            }
        }
        return results;
    }
}
```