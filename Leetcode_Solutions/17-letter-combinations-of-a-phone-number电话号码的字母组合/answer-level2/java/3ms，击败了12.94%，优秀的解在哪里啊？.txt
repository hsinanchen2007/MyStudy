### 解题思路
看注释吧

### 代码

```java
public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String>  ans = new ArrayList<>();

        if (digits.length() < 1) {
            return ans;
        }

        // 一次按键只有一个字母
        // 所以 digits的长度 = 最终字母组合的长度
        String[] letterArr = new String[digits.length()];
        backtrack(ans, digits, 0, letterArr);

        return ans;
    }

    private static final Map<Character, String[]> LETTER_DIGIT_MAP = new HashMap<Character, String[]>() {
        {
            put('2', new String[]{"a", "b", "c"});
            put('3', new String[]{"d", "e", "f"});
            put('4', new String[]{"g", "h", "i"});
            put('5', new String[]{"j", "k", "l"});
            put('6', new String[]{"m", "n", "o"});
            put('7', new String[]{"p", "q", "r", "s"});
            put('8', new String[]{"t", "u", "v"});
            put('9', new String[]{"w", "x", "y", "z"});
        }

    };

    /**
     * 回溯
     *
     * @param ans
     * @param digits
     * @param i
     * @param letterArr
     */
    private void backtrack(List<String> ans, String digits, int idx, String[] letterArr) {
        String[] arr = LETTER_DIGIT_MAP.get(digits.charAt(idx));
        for (int i = 0; i < arr.length; i++) {
            letterArr[idx] = arr[i];

            if (idx == digits.length() - 1) {
                // 结束
                ans.add(String.join("", letterArr));
            } else {
                //
                backtrack(ans, digits, idx + 1, letterArr);
            }
        }
    }
}
```