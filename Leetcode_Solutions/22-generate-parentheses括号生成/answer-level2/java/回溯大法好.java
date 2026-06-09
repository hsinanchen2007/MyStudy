### 解题思路
有点点经典的回溯题目

明确下面几点：
1. 最后的结果放在一个全局变量`res`里
2. 要构造的是一个字符串`str`
3. 可选项是左括号`left`和右括号`right`
4. 结束条件是构造的字符串`str`长度达到`2 * n`了（`n`是括号对数，一对括号长度为`2`）
5. 初始状态时，`str`是空字符串，可以使用的左括号数量是`n`，因为右括号必须在左括号的后面才算**有效的**，所以可以使用的右括号数量是`0`
6. 在做选择时，每次在字符串右侧加一个括号：
- 如果有可用的左括号（`left > 0`），就给字符串`str`填上一左括号，并且左括号可用数量`-1`，右括号可用数量`+1`
- 如果有可用的右括号（`right > 0`），就给字符串`str`填上一右括号，并且右括号可用数量`-1`

将以上带入"回溯大法模版"即可

```java
List<V> res;

public void backtrace(路径, 选择列表) {
    if(满足结束条件) {
        res.add(路径);
        return;
    }
    
    for(选择 : 选择列表) {
        做选择;
        backtrace(路径, 选择列表);
        撤销选择;
    }
}
```

### 代码

```java
class Solution {
    List<String> res;
    int len;

    public List<String> generateParenthesis(int n) {
        res = new ArrayList<>();
        len = n * 2;
        backtrace("", n, 0);
        return res;
    }

    public void backtrace(String str, int left, int right) {
        if(str.length() == len) {
            res.add(str);
            return;
        }
        if(left > 0) {
            backtrace(str + '(', left - 1, right + 1);
        }
        if(right > 0) {
            backtrace(str + ')', left, right - 1);
        }
    }
}
```