### 解题思路
我就是想把这个字符串转为数组，然后再排序，再比较，不相等则为false

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
            if (s1.length() == 0 && s2.length()==0) {
            return true;
        }
        if (s1.length() != s2.length()) {
            return false;
        }
        List<Character> s1List = new ArrayList<>();
        for (char c : s1.toCharArray()) {
            s1List.add(c);
        }
        List<Character> s2List = new ArrayList<>();
        for (char c : s2.toCharArray()) {
            s2List.add(c);
        }
        Collections.sort(s1List);
        Collections.sort(s2List);
        for (int i = 0, sum = s1List.size(); i < sum; i ++) {
            if (!s1List.get(i).equals(s2List.get(i))) return false;
        }
        return true;
    }
}
```