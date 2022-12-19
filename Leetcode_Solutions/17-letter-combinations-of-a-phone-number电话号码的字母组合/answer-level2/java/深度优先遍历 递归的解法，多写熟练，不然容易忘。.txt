### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<String> list = new ArrayList<>();
    Map<Integer, String> map = new HashMap<>();

    private void initMap() {
        map.put(2, "abc");
        map.put(3, "def");
        map.put(4, "ghi");
        map.put(5, "jkl");
        map.put(6, "mno");
        map.put(7, "pqrs");
        map.put(8, "tuv");
        map.put(9, "wxyz");
    }

    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.length() == 0) {
            return list;
        }
        initMap();
        dfs(digits, 0, "");
        return list;
    }

    private void dfs(String digits, int i, String s) {
        if (i == digits.length()) {
            list.add(s);
            return;
        }
        String string = map.get(Integer.parseInt(digits.substring(i, i + 1)));
        for (int j = 0; j < string.length(); j++) {
            String tmp = string.charAt(j) + "";
            dfs(digits, i + 1, s + tmp);
        }
    }
}
```