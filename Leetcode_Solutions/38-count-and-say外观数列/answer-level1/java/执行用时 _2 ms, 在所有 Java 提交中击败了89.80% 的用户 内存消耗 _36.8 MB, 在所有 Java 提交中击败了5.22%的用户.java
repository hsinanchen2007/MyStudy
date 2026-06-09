菜菜的我还是把代码贴了上来！
```
class Solution {
    public String countAndSay(int n) {
        StringBuilder start = new StringBuilder("1");
        for (int i = 1; i < n; i++) {
            start = deal(start);
        }
        return start.toString();
    }

    public StringBuilder deal(StringBuilder str) {
        int len = str.length();
        int count = 1;
        char c = str.charAt(0);
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < len - 1; i++) {
            if (c == str.charAt(i + 1)) {
                count++;
                continue;
            }
            result.append(count).append(c);
            count = 1;
            c = str.charAt(i + 1);
        }
        return result.append(count).append(c);
    }
}
```
