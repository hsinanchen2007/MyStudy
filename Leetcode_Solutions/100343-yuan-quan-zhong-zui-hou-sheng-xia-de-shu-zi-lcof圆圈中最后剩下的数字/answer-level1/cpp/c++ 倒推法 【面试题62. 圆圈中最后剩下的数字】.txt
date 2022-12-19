### 解题思路
最终剩下一个人时的安全位置肯定为0，反推安全位置在人数为n时的编号
人数为1： 0
人数为2： (0+m) % 2
人数为3： ((0+m) % 2 + m) % 3
人数为4： (((0+m) % 2 + m) % 3 + m) % 4
........
迭代推理到n就可以得出答案

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int result = 0;
        for (int i = 2; i <= n; ++i) {
            result = (result + m) % i;
        }
        return result;
    }
};
```