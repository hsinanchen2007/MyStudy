**一、分治法**
思想主要两步:
1. 把一个大的问题分解成小问题，小到什么程度呢？一般来说就是小到可以直接解决就算是小问题了，比如当前这个问题就是小到只有一个数字，此时可以直接得到当前问题的解。
2. 把上一步中分解得到小问题的解合并为最终问题的解。
```
class Solution {
    private int[] NUMBER = new int[] {2, 3, 4, 5, 6, 7, 8, 9};
    private String[][] STRS = new String[][] { 
        {"a", "b", "c" },
        {"d", "e", "f" },
        {"g", "h", "i" },
        {"j", "k", "l" },
        {"m", "n", "o" },
        {"p", "q", "r", "s" }, 
        {"t", "u", "v" },
        {"w", "x", "y", "z" },
        };

    public List<String> letterCombinations(String digits) {
        if (null == digits || digits.isEmpty()) {
            return Collections.emptyList();
        }
        return doCombinations(0, digits.length() - 1, digits);
    }
    private List<String> doCombinations(int start, int end, String digits) {
        List<String> result = new ArrayList<>();
        if (start == end) {//1 小到可以解决解决的问题，这里直接返回对应的字符列表。
            int index = digits.charAt(start) - 48 - 2;
            return Arrays.asList(STRS[index]);
        }
        int middle = (start + end) / 2;
        int startIndex = digits.charAt(start) - 48 - 2;
        int endIndex = digits.charAt(end) - 48 - 2;
        int middleIndex = digits.charAt(middle) - 48 - 2;
        
        List<String> leftStrs = doCombinations(start, middle, digits);
        List<String> rightStrs = doCombinations(middle + 1, end, digits);

        int nLeft = leftStrs.size();
        int nRight = rightStrs.size();
        //合并小问题的解，并最终得到原问题的解。
        for (int i = 0; i < nLeft; i++) {
            for (int j = 0; j < nRight; j++) {
                result.add(leftStrs.get(i) + rightStrs.get(j));
            }
        }

        return result;
    }
}
```

**二、回溯法**
思想是遍历整个解空间树（深度优先）
```
class Solution {
    private String[][] STRS = new String[][] { 
        {"a", "b", "c" },
        {"d", "e", "f" },
        {"g", "h", "i" },
        {"j", "k", "l" },
        {"m", "n", "o" },
        {"p", "q", "r", "s" }, 
        {"t", "u", "v" },
        {"w", "x", "y", "z" },
    };
    private List<String> result = new ArrayList<>();

    public List<String> letterCombinations(String digits) {
        if (null == digits || digits.isEmpty()) {
            return Collections.emptyList();
        }
        backRetrace("", digits);
        return result;
    }

    private void backRetrace(String str, String digits) {
        if (digits.isEmpty()) {//得到一个解，这里保存起来就行
            result.add(str);
            return;
        }
        
        int index = digits.charAt(0) - 48 - 2;
        String[] strArray = STRS[index];
        for (int i = 0; i < strArray.length; i++) {
            backRetrace(str + strArray[i], digits.substring(1));//深度遍历下去
        }
    }
}
```
