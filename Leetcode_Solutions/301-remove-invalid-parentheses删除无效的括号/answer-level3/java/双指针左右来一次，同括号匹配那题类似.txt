### 解题思路
执行用时 :5 ms, 在所有 Java 提交中击败了80.49%的用户
内存消耗 :36.4 MB, 在所有 Java 提交中击败了92.48%的用户

正向处理 右边括号 ')' 多余 左括号 '(' 的情况, 方向同理

### 代码

```java
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ret2 = new LinkedList<>();
        if (s == null) {
            return ret2;
        }
        // 先获取正向处理的字符串
        List<String> ret = new LinkedList<>(reformatStringZX(s));
        // 将正向字符串进行反向处理
        for (int i = 0; i < ret.size(); i++) {
            ret2.addAll(reformatStringFX(ret.get(i)));
        }
        return ret2;
    }
    // 正向处理
    private HashSet<String> reformatStringZX(String s) {
        HashSet<String> ret = new HashSet<>();
        // 初始化为""
        ret.add("");
        if (s.equals("")) {
            return ret;
        }

        int left = 0, right = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else if (s.charAt(i) == ')') {
                right++;
            } else {
                continue;
            }
            // 如果左边和右边括号相等，则说明符合有效，将它与前面的连起来
            if (right == left) {
                String cur = s.substring(start, i + 1);
                HashSet<String> newSet = new HashSet<>();
                for (String str : ret) {
                    newSet.add(str + cur);
                }
                ret = newSet;
                start = i + 1;
            } else if (right > left) {
                // 如果右边括号多了一个，则前面有效的所有字符串中，任何位置都可以删除一个')'成为新的不同字符串
                // 用hashSet去重
                String cur = s.substring(start, i + 1);
                String preCur = s.substring(start, i);
                // 将前面的所有情况那出来
                HashSet<String> newSet = new HashSet<>();
                for (String str : ret) {
                    newSet.add(str + preCur);
                    for (int k = str.length() - 1; k >= 0; k--) {
                        if (str.charAt(k) == ')') {
                            newSet.add(str.substring(0, k) + str.substring(k + 1) + cur);
                        }
                    }
                }
                ret = newSet;
                start = i + 1;
                left = 0;
                right = 0;
            }
        }

        // 将后面没有处理的加进来 然后反过来执行一次
        String cur = s.substring(start);
        if (!cur.equals("")) {
            HashSet<String> newSet = new HashSet<>();
            for (String str : ret) {
                newSet.add(str + cur);
            }
            ret = newSet;
        }

        return ret;
    }
    // 反向处理，同理
    private HashSet<String> reformatStringFX(String s) {
        HashSet<String> ret = new HashSet<>();

        ret.add("");
        if (s.equals("")) {
            return ret;
        }
        int left = 0, right = 0;
        int end = s.length();
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == ')') {
                right++;
            } else if (s.charAt(i) == '(') {
                left++;
            } else {
                continue;
            }

            if (right == left) {
                String cur = s.substring(i, end);
                HashSet<String> newSet = new HashSet<>();
                for (String str : ret) {
                    newSet.add(cur + str);
                }
                ret = newSet;
                end = i;
            } else if (right < left) {
                String cur = s.substring(i, end);
                String preCur = s.substring(i + 1, end);
                // 将前面的所有情况那出来
                HashSet<String> newSet = new HashSet<>();
                for (String str : ret) {
                    newSet.add(preCur + str);
                    for (int k = 0; k < str.length(); k++) {
                        if (str.charAt(k) == '(') {
                            newSet.add(cur + str.substring(0, k) + str.substring(k + 1));
                        }
                    }
                }
                ret = newSet;
                end = i;
                left = 0;
                right = 0;
            }
        }

        String cur = s.substring(0, end);
        if (!cur.equals("")) {
            HashSet<String> newSet = new HashSet<>();
            for (String str : ret) {
                newSet.add(cur + str);
            }
            ret = newSet;
        }
        return ret;
    }
}
```