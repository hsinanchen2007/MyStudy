### 解题思路
原答主链接;https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/

### 代码

```java
class Solution{
    public List<String> generateParenthesis(int n) {
            LinkedList<LinkedList<String>> result = new LinkedList<LinkedList<String>>();
            if (n == 0)
                return result.get(0);
            LinkedList<String> list0 = new LinkedList<String>();
            list0.add("");
            result.add(list0);
            LinkedList<String> list1 = new LinkedList<String>();
            list1.add("()");
            result.add(list1);
            for (int i = 2; i <= n; i++) {
                LinkedList<String> temp = new LinkedList<String>();
                for (int j = 0; j < i; j++) {
                    List<String> str1 = result.get(j);
                    List<String> str2 = result.get(i - 1 - j);
                    for (String s1 : str1) {
                        for (String s2 : str2) {
                            String el = "(" + s1 + ")" + s2;
                            temp.add(el);
                        }
                    }

                }
                result.add(temp);
            }
            return result.get(n);
    }   
}

```