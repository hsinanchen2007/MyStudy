### 解题思路

思路很简单，我们尝试按照 `popped` 中的顺序模拟一下出栈操作，如果符合则返回 `true`，否则返回 `false`。这里用到的贪心法则是**如果栈顶元素等于 popped 序列中下一个要 pop 的值，则应立刻将该值 pop 出来**。

我们使用一个栈 `st` 来模拟该操作。将 `pushed` 数组中的每个数依次入栈，同时判断这个数是不是 `popped` 数组中下一个要 `pop` 的值，如果是就把它 `pop` 出来。最后检查栈是否为空。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/809621a1b20066aeb90344ef1a0efda00dff14893fb65a9efed3219525011523-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/af2ae156e0be053b5226eadddd71b1f954de1358f7f147eab630b885a38b2f2f-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/37b5f36b3f13be2ca25c394f30fae2980d5bddfa9425a9f713e9f2e5ba81aabf-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/2eb66b9e3df876de0b51d97629d9c29c3a20809b7ae56ec8e2b9f80cb7cf140b-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/17246a9d284a583681f31063eafffdd0d825ece6a0011b2cb2794dccc31af66b-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/21d8299ddd0f3f7a2d189052b5bc03529db71921f4eabb442ee1fe811fb1345c-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/7acd6853338a744cd603661042146683825f01806463f1903463398925007fe2-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/0282be3175982cc8c08872eb0a40b7ded9049739cc57537000a2f2a788b2f9f5-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/557cd5263916bc49701cdc606e419f1aab44975fad222a1d5ff6a7910e581c68-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/a0e11fe9a6c224bdb7b68647588b8c01b1a704ee0ad64b69caace2c0d1b0226d-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/51c7879f302dc798d226f015e76dd644abaae615647f76bb45fda1150a9771ae-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG)>


#### 算法
- 初始化栈 `stack`，`j = 0`；
- 遍历 `pushed` 中的元素 `x`；
    - 当 `j < popped.size()` 且栈顶元素等于 `popped[j]`：
        - 弹出栈顶元素；
        - `j += 1`；
- 如果栈为空，返回 `True`，否则返回 `False`。


#### 代码
```cpp []
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = popped.size();
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i){
            st.push(pushed[i]);
            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};
```
```python []
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        j = 0
        for x in pushed:
            stack.append(x)
            while stack and j < len(popped) and stack[-1] == popped[j]:
                stack.pop()
                j += 1
        return not stack
```
### 复杂度分析
- 时间复杂度：$O(N)$。将所以元素一遍入栈，一遍出栈，需要 $O(2N)$。
- 空间复杂度：$O(N)$。使用了辅助栈 `st`。

如果您有任何建议欢迎讨论~
