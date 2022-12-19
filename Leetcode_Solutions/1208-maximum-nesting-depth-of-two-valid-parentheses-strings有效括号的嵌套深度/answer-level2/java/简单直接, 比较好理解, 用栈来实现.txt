### 解题思路
因为 A.length + B.length 等于 seq.length, 就是两者之和一定, 找出使得两者的最大值最小的情况, 那么一定是两者大小最接近的时候. 表达式有效的话, 只需要分配 '(' 即可, 就按照 ABABAB...这样的顺序分配即可. 联想之前的有效括号那题, 本题也可以使用栈来实现.
1. 遇到 '(' 的时候, 先判断栈的大小, 即栈中的 '(' 个数, 如果为偶数个, 那么该 '('是属于 A 的, 对应的数组下标应该为 0; 栈的大小为奇数个, 同理, 下标为 1;然后再入栈 ;
2. 遇到 ')' 的时候, 同样也判断栈的大小, 为偶数个, 那么该 ')' 对应的 ‘(’ 应该是 B 的, 对应数组下标为 1; 栈的大小为奇数也同理. 然后再出栈.
3. 基本就上面的对应关系弄明白就可以, 实现比较简单.

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        Stack<Character> s = new Stack<>();
        int[] ans = new int[seq.length()];
        int index = -1;
        for(char ch : seq.toCharArray()) {
            if (ch == '(') {
                if (s.size() % 2 == 0) {
                    ans[++index] = 0;
                } else {
                    ans[++index] = 1;
                }
                s.push(ch);
            } else {
                if (s.size() % 2 == 0) {
                    ans[++index] = 1;
                } else {
                    ans[++index] = 0;
                }
                s.pop();
            }
        }
        return ans;
    }
}
```