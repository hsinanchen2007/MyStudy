### 解题思路
### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
 List<String> result = new ArrayList<String>((int) Math.pow(4, digits.length()));
        String[] array = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.length(); i++) {
            int value = Integer.valueOf(digits.substring(i, i + 1));
//过滤掉空字符的数字
            if (value < 2) {
                continue;
            }
            if (result.size() == 0) {
                for (char character : array[value].toCharArray()) {
                    result.add("" + character);

                }
            } else {
                int temp = result.size();
                for (int m = 1; m < array[value].length(); m++) {
                    for (int j = 0; j < temp; j++) {
                        result.add(result.get(j) + array[value].charAt(m));
                    }
                }
                for (int j = 0; j < temp; j++) {
                    result.set(j, result.get(j) + array[value].charAt(0));
                }
            }
        }
        return result;
    }
}
```