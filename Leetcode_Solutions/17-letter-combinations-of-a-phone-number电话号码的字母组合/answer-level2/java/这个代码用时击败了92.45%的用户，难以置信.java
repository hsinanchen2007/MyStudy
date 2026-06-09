### 解题思路
无脑把得到的字母按顺序排队。击败了92.45%的用户，难以置信

### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        String[] str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> r = new ArrayList<String>();
        ArrayList<Integer> nums = new ArrayList<Integer>();
        for (int i = 0; i < digits.length(); i++)
            nums.add(Integer.parseInt(digits.substring(i, i + 1)));
        for (int i = 0; i < nums.size(); i++) {
            r = addString(r, str[nums.get(i)]);
        }
        return r;
    }

    private static List<String> addString(List<String> r, String s) {
        List<String> rs = new LinkedList<String>();
        if (r.size() == 0) {
            for (int j = 0; j < s.length(); j++) {
                rs.add(s.substring(j, j + 1));
            }
        } else {


            for (int i = 0; i < r.size(); i++) {
                for (int j = 0; j < s.length(); j++) {
                    rs.add(r.get(i) + s.substring(j, j + 1));
                }
            }
        }
        return rs;
    }
}
```