### 解题思路
迭代法需要找清楚每次增加一个按键，结果如何走向的问题，用数学迭代法的思想解决问题。

### 代码

```java
class Solution {
      Map<Integer, String> map = new HashMap<>();

    public List<String> letterCombinations(String digits) {
        List<String> results = new ArrayList<>();
        if (digits.length() == 0) {
            return results;
        }
        initMap();
        char[] chars = digits.toCharArray();
        int num1 = Integer.parseInt(String.valueOf(chars[0]));
        String string1 = map.get(num1);
        int length1 = string1.length();
        for (int i = 0; i < length1; i++) {
            results.add(String.valueOf(string1.charAt(i)));
        }

        for (int i = 1; i < chars.length; i++) {
            int num = Integer.parseInt(String.valueOf(chars[i]));
            String string = map.get(num);
            int length = string.length();
            List<String> copy = new ArrayList<>(results);
            results.clear();
            int copyLength = copy.size();
            for (int j = 0; j < length; j++) {
                for (int k = 0; k < copyLength; k++) {
                    List<String> tmp = new ArrayList<>(copy);
                    results.add(tmp.get(k) + string.charAt(j));
                }
            }
        }
        return results;
    }

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
}
```