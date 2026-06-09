### 解题思路
标准的dfs, 非常标准

### 代码

```java

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "()())()";
        List<String> list = solution.removeInvalidParentheses(s);
        list.forEach(s1 -> {
            System.out.println("s1 = " + s1);
        });
    }


    public List<String> removeInvalidParentheses(String s) {
        /**
         * 这道题是标准的dfs. 非常清晰
         * 1,记录要删的'{'数量和要删的'}'数量. 记住,一定要先判断'{'. this is a trick.
         * 2,然后dfs,用set记录.
         */
        HashSet<String> set = new HashSet<>();
        int index = 0;
        int leftToDelete = 0;
        int rightToDelete = 0;
        int leftCount = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                leftToDelete++;
            } else if (c == ')') {
                if (leftToDelete > 0) {
                    leftToDelete--;
                } else {
                    rightToDelete++;
                }
            }
        }
        dfs(s, index, leftCount, leftToDelete, rightToDelete, set, new StringBuilder());

        ArrayList<String> list = new ArrayList<>();
        list.addAll(set);
        return list;
    }

    private void dfs(String s, int index, int leftCount, int leftToDelete, int rightToDelete, HashSet<String> set, StringBuilder sb) {
        if (index == s.length()) {
            if (leftToDelete == 0 && rightToDelete == 0 && leftCount == 0) {
                set.add(sb.toString());
                
            }
            return;
        }
        char c = s.charAt(index);
        if (c == '(') {
            // 如果是'{',那么要么删除,要么保留.
            // 如果删除
            if (leftToDelete > 0) {
                StringBuilder tmp = new StringBuilder(sb);
                dfs(s, index + 1, leftCount, leftToDelete - 1, rightToDelete, set, tmp);
            }
            // 不删,或者没有可以删除的
            StringBuilder tmp = new StringBuilder(sb);
            tmp.append(c);
            dfs(s, index + 1, leftCount + 1, leftToDelete, rightToDelete, set, tmp);
        } else if (c == ')') {
            // 如果是'}', 要么删除,要么在前面有'{'的时候保留.否则只能删除
            if (rightToDelete > 0) {
                StringBuilder tmp = new StringBuilder(sb);
                dfs(s, index + 1, leftCount, leftToDelete, rightToDelete - 1, set, tmp);
            }
            if (leftCount > 0) {
                StringBuilder tmp = new StringBuilder(sb);
                tmp.append(c);
                dfs(s, index + 1, leftCount - 1, leftToDelete, rightToDelete, set, tmp);
            } else {
                return;
            }
        } else {
            StringBuilder tmp = new StringBuilder(sb);
            tmp.append(c);
            dfs(s, index + 1, leftCount, leftToDelete, rightToDelete, set, tmp);
        }
    }
}

```