为了能够方便取到倒数第一个数与倒数第二个数，这里用一个vector来模拟栈行为
```
class Solution {
public:
    bool isValid(string S) {
        int N = S.size();
        vector<char> st(N, '#');
        int top = 0;
        for (int i = 0; i < N; ++i) {
            if (top >= 2 && st[top - 1] == 'b' && st[top - 2] == 'a' && S[i] == 'c') {
                top -= 2;
            } else {
                st[top++] = S[i];
            }
        }
        return top == 0;
    }
};
```
![image.png](https://pic.leetcode-cn.com/3893e808e44f6ba9c1fdbe846bd322517fa7a1ed001c1e0b18c8bb028c31bcf6-image.png)
