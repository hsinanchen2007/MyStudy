# DFS枚举所有组合

> 思路

1. 我们有输入字符串 $S = "23456"$
2. 先枚举S中的每个字符,如第1位的 `2`
3. 枚举每个数字字符对应的字母序列, 如`2`对应的 $"abc"$
4. 使用一个中间集合变量存储历史已经拼接完成的字符, 开始时state集合只有一个空字符串. 遍历state集合, 将其中的每个串与上述单个字符第3步中的每个字符拼接起来. 将新生成的结果加入到一个新的集合变量中, 如tmp集合.
5. 遍历完state集合, 将state指向新拼接的集合. 

> 图解

![image.png](https://pic.leetcode-cn.com/683bb6e174c25d16a76bb3a66c25bbb155ef7b7ad819d09c1718cc735ff6a1c0-image.png)


> 代码

```java
class Solution {
    
    String[] board = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n;
    
    public List<String> letterCombinations(String digits) {
        n = digits.length();
        if(n <= 0) return new LinkedList();
        
        Set<String> state = new HashSet();
        state.add("");
        for(int i = 0; i < n; i++){
            String part1 = board[digits.charAt(i) - '2'];
            Set<String> tmp = new HashSet();
            for(int j = 0; j < part1.length(); j++){
                for(String s : state){
                    tmp.add(s + part1.charAt(j));
                }
            }
            state = tmp;
        }
        
        return new LinkedList(state);
    }
}
```

> 复杂度

- 时间复杂度: O($4^N$)
- 空间复杂度: O($4^N$)