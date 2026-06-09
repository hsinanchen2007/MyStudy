自定义排序，根据优先级大小来排
```java
class Solution {
    public String customSortString(String S, String T) {
        char[] s = S.toCharArray();
        char[] t = T.toCharArray();
        Character[] t2 = new Character[t.length];
        int[] id = new int[30];
        for (int i = 0; i < s.length; i++) {
        	id[s[i]-'a'] = i;
        }
        for (int i = 0; i < t.length; i++)
        	t2[i] = t[i];
        Arrays.sort(t2, (Character x, Character y) -> id[x-'a']-id[y-'a']);
        for (int i = 0; i < t.length; i++)
        	t[i] = t2[i];
        return new String(t);
    }
}
```
