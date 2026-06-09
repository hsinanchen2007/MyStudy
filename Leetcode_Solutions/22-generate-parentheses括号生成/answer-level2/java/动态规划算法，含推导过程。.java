### 解题思路

![image.png](https://pic.leetcode-cn.com/567495a33ac82cef62bafc3665880270d724c5a99591e64724375b2a676906bf-image.png)

### 代码

```java
class Solution {

    public List<String> generateParenthesis(int n) {
       List<List<String>> result = new ArrayList<>();
        if (n == 0)
            return result.get(0);
        List<String> list0 = new ArrayList<String>();
        list0.add("");
        result.add(list0);
        List<String> list1 = new ArrayList<String>();
        list1.add("()");
        result.add(list1);
        for (int i = 2; i <= n; i++) {
            List<String> temp = new ArrayList<String>();
            for (int j = 0; j < i; j++) {
                List<String> listJ = result.get(j);
                List<String> listI = result.get(i - 1 - j);
                for (String s1 : listI) {
                    for (String s2 : listJ) {
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