### 解题思路
此处撰写解题思路
类似穷举。
### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            List<String> result = new ArrayList();
            return result;
        }
        String[] shuzi = new String[] {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> result = Arrays.asList(new String[] {""});
        for (int i = 0; i < digits.length(); i++) {
            String tmpString = shuzi[digits.charAt(i) - '2'];
            List<String> tmpResult = new ArrayList();
            for (int j = 0; j < tmpString.length(); j++) {
                for (int k = 0; k < result.size(); k++) {
                    String tmp = result.get(k) + tmpString.charAt(j);
                    tmpResult.add(tmp);
                }
            }
            result = tmpResult;
        }
        return result;
    }
}
```