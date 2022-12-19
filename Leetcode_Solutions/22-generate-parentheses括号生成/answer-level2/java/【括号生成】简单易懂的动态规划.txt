# 思路

利用动态规划的思想，每一步产生的所有括号都是在上一步的基础上加上一对括号生成的。

为了使每一步加的括号都是有效的括号，通过观察，可以加在上一步的括号的右括号（")"）的左边，都是有效的括号，此时可能会产生重复的结果，所以，利用HashSet不能添加重复数据的特性，进行判断之后再添加。最后，再加上一个外部的括号，就完整了。

# 代码

```
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> totalList = new ArrayList<>();
        if (n == 0)
            return totalList;
        //n=1时，只有一个括号
        totalList.add("()");
        for (int i = 2; i <= n; i++) {
            HashSet<String> set = new HashSet<String>();
            List<String> list = new ArrayList<>();
            //遍历列表里的每一个括号字符串
            for (int j = 0; j < totalList.size(); j++) {
                String s = totalList.get(j);
                String temp = "";
                //在每一个括号字符串上加上合适的括号对
                for (int k = 0; k < s.length() - 1; k++) {
                    temp += s.charAt(k);
                    if (s.charAt(k + 1) == ')') {
                        temp += "()";
                        temp += s.substring(k + 1, s.length());
                        //利用HashSet不能添加重复数据的特性，判断是否已添加过同样的括号
                        if (set.add(temp)) {
                            list.add(temp);
                        }
                        temp = s.substring(0, k + 1);
                    }
                }
            }
            //最后在最后一个括号的外部加上一对括号
            list.add(totalList.get(totalList.size()-1) + "()");
            totalList = list;
        }
        return totalList;
    }
}
```
