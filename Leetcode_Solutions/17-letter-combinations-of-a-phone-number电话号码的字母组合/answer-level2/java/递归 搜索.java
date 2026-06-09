### 解题思路
递归列出所有情况

### 代码

```java
class Solution {

    String[] a = new String[]{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = 0;
    List<String> res = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return res;
        len = digits.length();
        find(digits, 0, "");
        return res;
    }

    void find(String di, int n, String s) {
        if (n == len) res.add(s);
        else {
            String t = a[di.charAt(n) - '2'];
            for (int i = 0; i < t.length(); i++) {
                find(di, n + 1, s + t.charAt(i));
            }
        }
    }
}
```