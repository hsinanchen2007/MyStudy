### 解题思路
![image.png](https://pic.leetcode-cn.com/6d1ea6bb05033158d0e2905a79c7526ca7d480aae77427042cd5de3da62cd01a-image.png)

通过简单观察可以发现，最后#的数量肯定比数字多一个。

所以考虑到前序遍历先根后左右的特性，思路就是，每次遇到数字就直接push，遇到#就pop。

当字符是#时，判断栈是否为空，如果是空的，再判断是否已经是字符串最后了，不是最后的话说明#的位置错了，反之说明是正确的前序遍历。

栈不为空就直接pop，i++是为了跳过分隔符。

类型选了bool是因为选啥都行，只是占位符而已，所以尽量选个简单的。

### 代码

```cpp
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return false;
        stack<bool> s;
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] == '#') {
                if (s.empty()) return i == preorder.size() - 1;
                else {
                    s.pop();
                    i++;
                }
            }
            else {
                while (i < preorder.size() && preorder[i] != ',') i++;
                s.push(0);
            }
        }
        return false;
    }
};
```