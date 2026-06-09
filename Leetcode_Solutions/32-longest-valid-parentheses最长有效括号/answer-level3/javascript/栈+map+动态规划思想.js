### 解题思路
使用栈来记录`(`的下标
使用一个pre object（相当于map）来记录已经计算过的长度，格式为 结尾下标：长度
每次匹配到左括号则入栈
每次匹配到右括号，则判断stack是否为空，如果为空，说明是个非法右括号，就什么也不做
如果不为空，则先计算当前这个括号的长度（当前下标-pop出来的下标+1）
在判断start左边一个括号是否在pre对象里，在的话，长度应该加上它的值
然后更新pre对象
```
()()
i=0:  0入栈
i=1:  0出栈 更新pre[1] = 2
i=2:  2入栈
i=3:  2出栈，计算当前括号为2，上一个括号pre[2-1] 存在，且为2，所以当前最大值就是2+pre[1] = 4
max = 4
```

### 代码

```javascript []
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let max = 0;
    if (!s || s.length === 0) return 0;
    let stack = [];
    // 记录上一个
    let pres = {};
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            stack.push(i);
        } else {
            if (stack.length !== 0) {
                let start = stack.pop();
                let count = i - start + 1;
                // 如果存在上一个数值，且是相连的
                if (start !== 0 && pres[start-1]) {
                    pres[i] = count + pres[start-1];
                } else {
                    pres[i] = count;
                }
                max = max > pres[i] ? max : pres[i];
            }
        }
    }
    return max
};
```
```java []
class Solution {
    public int longestValidParentheses(String s) {
        int max = 0;
        if (s.length() == 0) return 0;
        Stack<Integer> stack = new Stack<>();
        HashMap<Integer, Integer> pres = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (!stack.isEmpty()) {
                    int start = stack.pop();
                    int count = i - start + 1;
                    // 如果存在上一个数值，且是相连的
                    if (start != 0 && pres.containsKey(start - 1)) {
                        count = count + pres.get(start - 1);
                        pres.put(i, count);
                    } else {
                        pres.put(i, count);
                    }
                    max = max > count ? max : count;
                }
            }
        }
        return max;
    }
}
```