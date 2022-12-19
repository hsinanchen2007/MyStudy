### 解题思路
0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :38.3 MB, 在所有 Java 提交中击败了5.16%的用户

把它想象成不定位进制数，逢3或4进1，目标是显示所有数。
比如 12
ad bd cd 进位 ae be ...

### 代码

```java
class Solution {
    private static char[][] keyboard = new char['A'][];

    static {
        keyboard['2'] = new char[]{'a', 'b', 'c'};
        keyboard['3'] = new char[]{'d', 'e', 'f'};
        keyboard['4'] = new char[]{'g', 'h', 'i'};
        keyboard['5'] = new char[]{'j', 'k', 'l'};
        keyboard['6'] = new char[]{'m', 'n', 'o'};
        keyboard['7'] = new char[]{'p', 'q', 'r', 's'};
        keyboard['8'] = new char[]{'t', 'u', 'v'};
        keyboard['9'] = new char[]{'w', 'x', 'y', 'z'};
    }

    public List<String> letterCombinations(String digits) {
        char[] ds = digits.toCharArray();
        int digCount = ds.length;
        if (digCount == 0) return new ArrayList<>();
        int size = 1;
        for (char d : ds) {
            size *= keyboard[d].length;
        }

        List<String> s = new ArrayList<>(size);
        int[] ptr = new int[digCount + 1];
        while (ptr[digCount] == 0) {
            StringBuilder sb = new StringBuilder(digCount);
            for (int j = 0; j < digCount; j++) {
                char[] cs = keyboard[ds[j]];
                sb.append(cs[ptr[j]]);
            }
            s.add(sb.toString());
            ptr[0] ++;
            for (int j = 0; j < ptr.length - 1; j++) {
                if (ptr[j] >= keyboard[ds[j]].length) {
                    ptr[j + 1] ++;
                    ptr[j] = 0;
                }
            }
        }
        return s;
    }

}
```