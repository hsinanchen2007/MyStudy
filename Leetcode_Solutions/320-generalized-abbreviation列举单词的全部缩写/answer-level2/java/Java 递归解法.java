### 解题思路

用递归来解

因为一个单词里面可能有多个数字，所以递归的的时候应该用一个变量start来记录目前我们递归的位置。

### 代码

```java
class Solution {
    List<String> res = new ArrayList<>();
    public List<String> generateAbbreviations(String word) {
        helper(word, 0);
        res.add(word);
        return res;
    }

    void helper(String word, int start) {
        for (int i = start; i < word.length(); i ++) {
            for (int j = 1; j <= word.length() - i; j ++) {
                String r = word.substring(0, i) + j + word.substring(i + j);
                res.add(r);
                String jString = "" + j;
                helper(r, i + jString.length() + 1);
            }
        }
    }
}
```