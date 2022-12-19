### 解题思路
主要思想: 一个萝卜一个坑
不停的交换位置, 直到所有元素都被交换一次为止.
注意当s.size()%n == 0时会交换重复的元素, 要做检查并跳过, if的作用就是这个.

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int count = 0, length = s.length();
        int i = 0, pos = i, next;
        while (count < length - 1) {
            next = (pos + n) % length;
            if (next == i) {
                pos = ++i;
                next = (pos + n) % length;
                ++count;
            }
            swap(s[pos], s[next]);
            pos = next;
            ++count;
        }
        return s;
    }
};
```