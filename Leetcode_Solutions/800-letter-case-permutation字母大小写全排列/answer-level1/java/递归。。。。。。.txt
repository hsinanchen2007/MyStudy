### 解题思路
用时内存都很差，求指点

### 代码

```java
class Solution {
    private List<String> ress = new ArrayList<>();

    public List<String> letterCasePermutation(String S) {
        if (S.length() == 0)
            return ress;
        changeLetter(S, "");
        return ress;
    }

    private void changeLetter(String s, String res) {
        if (res.length() == s.length()) {
            ress.add(res);
            return;
        }
        for (int i = res.length(); i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isLetter(c)) {
                //是小写
                if (c <= 'z' && c >= 'a')
                    changeLetter(s, res + (c + "").toUpperCase());
                else
                    changeLetter(s, res + (c + "").toLowerCase());
            }
            res += c;
        }
        ress.add(res);
    }
}
```