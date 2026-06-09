括号匹配常见的解题思路就是栈。
当栈的 size 超过 1 时就说明出现了嵌套，我们只要争取把嵌套的'('平分给 A，B就好了，利用栈顶指针的奇偶性是一个很好的平分策略。

```
int data[10000] = {0};
int top = 0;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(), 0);
        for(int i = 0, n = seq.size(); i < n; i++) {
            if(seq[i] == '(') {
                ::data[top++] = i;
            } else {
                if(((--top)&1) == 1) {
                    res[i] = 1;
                    res[::data[top]] = 1; 
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8c312aac79eb375ddd9c1b13e6721c2af280e350aeb41e0fa26a5359bce159ef-image.png)

